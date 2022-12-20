// 1143. Longest Common Subsequence

// Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.
// A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.
// For example, "ace" is a subsequence of "abcde".
// A common subsequence of two strings is a subsequence that is common to both strings.

// Example 1:

// Input: text1 = "abcde", text2 = "ace"
// Output: 3
// Explanation: The longest common subsequence is "ace" and its length is 3.

// This question is based on Dp and it is very standard question of dp and string.
// Logic is there on notebook

// TC - O(N)
// SC - O(N)
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int helper(string &txt1, int n1, string &txt2, int n2, vector<vector<int>> &dp)
    {
        if (n1 < 0 || n2 < 0) // When traversing the string, pointer surpass the 0th index then return 0
        {
            return 0;
        }
        if (dp[n1][n2] != -1) // Memoization
        {
            return dp[n1][n2];
        }
        if (txt1[n1] == txt2[n2]) // If both char equal then decrement both the indexes and add 1 and return
        {
            return dp[n1][n2] = 1 + helper(txt1, n1 - 1, txt2, n2 - 1, dp);
        }

        return dp[n1][n2] = max(helper(txt1, n1 - 1, txt2, n2, dp), helper(txt1, n1, txt2, n2 - 1, dp)); // If not equal the we have choice either we can decrement n1 or n2 so, try to decrement n1 and n2 is same then n1 is same and n2 decremented, return back to previous node the max of both the cases or choices.
    }
    int longestCommonSubsequence(string text1, string text2)
    {
        int a = text1.size();
        int b = text2.size();
        vector<vector<int>> dp(a, vector<int>(b, -1)); // This is the way to initialize every element of 2D vector by -1
        return helper(text1, a - 1, text2, b - 1, dp);
    }
};
