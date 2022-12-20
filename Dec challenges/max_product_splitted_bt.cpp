// 1339. Maximum Product of Splitted Binary Tree
// Given the root of a binary tree, split the binary tree into two subtrees by removing one edge such that the product of the sums of the subtrees is maximized.
// Return the maximum product of the sums of the two subtrees. Since the answer may be too large, return it modulo 109 + 7.
// Note that you need to maximize the answer before taking the mod and not after taking it.

// Example 1:

// Input: root = [1,2,3,4,5,6]
// Output: 110
// Explanation: Remove the red edge and get 2 binary trees with sum 11 and 10. Their product is 110 (11*10)

//Approach :

//We don't have to find the sum of both subtree, we can find the total sum and subtract the sum of 1 subtree from that then we will get sum of another subtree.

//This is the application of post order traversal for finding the sum of 1 subtree while you can 
//find the total sum by any traversal.

//TC - O(N)
//SC - O(N)

#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    long long total_sum=0; //Made global variable of totalsum so that we can able to find totalsum and our final ans with 1 function call only because as many times we will call the function these values will be going to update and we can make use of these values. 
//For example when we first time call our find_final_ans fun in main, it will update total_sum globally and ans will be 0 and when we will call second time then it will update our ans as well globally.
    long long ans=0;
    int mod=pow(10,9)+7;
    int find_final_ans(TreeNode* root)
    {
        if(root==NULL)//edge case
        {
            return 0;
        }
        int sum=find_final_ans(root->left) + find_final_ans(root->right) + root->val; //finding the sum - total sum as well as sum of 1 subtree because eventually we are finding the sum and the method will be same so why should we call different function for both operation.
        ans=max(ans,(total_sum-sum)*sum); //Updating the ans 
        return sum;  //It will return total sum 1st time and 2nd time we are not caring what it return as our ans has got updated with correct value. 
    }
    int maxProduct(TreeNode* root) {
        total_sum=find_final_ans(root); //calling 1st time for total sum
        find_final_ans(root); //calling 2nd time to update ans
        return ans%mod; //Return the final ans
       
        
    }
};