// 931. Minimum Falling Path Sum

// Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.
// A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

// Example 1:

// Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
// Output: 13
// Explanation: There are two falling paths with a minimum sum as shown.

#include <bits/stdc++.h>
using namespace std;
// This method should be used when you are allowed to change the input matrix otherwise use the below method of memoization.

// TC - O(N^2)
// SC - O(1)
class Solution
{
public:
    int general_min(int a, int b, int c) // We have made this function to calculate normal minimum cost when we have 3 path to explore or when pointer is not at start or at end, it is there somewhere in mid.
    {
        return min(a, min(b, c));
    }
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int rowsize = matrix.size();
        int colsize = matrix[0].size();
        int ans = INT_MAX;
        for (int r = 1; r < rowsize; r++) // Matrix traversal
        {
            for (int c = 0; c < colsize; c++)
            {
                int leftD, middle, rightD; // Made variable to explore the possible path according the question
                if (c == 0)                // When pointer is at first column then it can't go to left that's why removed that option
                {
                    rightD = matrix[r - 1][c + 1];
                    middle = matrix[r - 1][c];
                    matrix[r][c] += min(rightD, middle); // Making changes at the current element by adding current element and min of 2 possible path.
                }
                else if (c == (colsize - 1)) // When pointer is at last then it can't go to right that's why removed that option
                {
                    leftD = matrix[r - 1][c - 1];
                    middle = matrix[r - 1][c];
                    matrix[r][c] += min(leftD, middle);
                }
                else
                { // Otherwise explore all the path
                    leftD = matrix[r - 1][c - 1];
                    middle = matrix[r - 1][c];
                    rightD = matrix[r - 1][c + 1];
                    matrix[r][c] += general_min(leftD, middle, rightD); // Making changes at the current element by adding current element and min of 3 possible path.
                }
            }
        }
        for (int i = 0; i < colsize; i++)
        {
            ans = min(ans, matrix[rowsize - 1][i]); // Here iterating the last row as all the changes have been made and min must be stored in this row so finding the min sum in last row and updating our ans.
        }
        return ans;
    }
};

// Below method uses memoization technique of DP in which we take 1 size larger dp vector and optimize the recursion but here problem is
// TC - O(N^2)
// SC - O(N^2)

// class Solution {
// public:
//     int minFallingPathSumHelper(vector<vector<int>>& matrix, int r, int c, vector<vector<int>>& dp){
//         if(r == 0 and c < matrix[0].size() and c >= 0) return matrix[r][c];
//         if(c >= matrix[0].size() or c < 0) return INT_MAX;

//         if(dp[r][c] != INT_MAX) return dp[r][c];
//         return dp[r][c] = matrix[r][c] + min(min(minFallingPathSumHelper(matrix, r-1, c+1, dp), minFallingPathSumHelper(matrix, r-1, c, dp)), minFallingPathSumHelper(matrix, r-1, c-1, dp));

//     }
//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int rows = matrix.size(), cols = matrix[0].size();
//         vector<vector<int>> dp(rows+1, vector<int>(cols+1, INT_MAX));
//         int ans = INT_MAX;
//         for(int c=0; c < cols; c++){
//             ans = min(ans, minFallingPathSumHelper(matrix, rows-1, c, dp));
//         }
//         return ans;
//     }
// };