// 124. Binary Tree Maximum Path Sum

// A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.
// The path sum of a path is the sum of the node's values in the path.
// Given the root of a binary tree, return the maximum path sum of any non-empty path.

// Example 1:

// Input: root = [1,2,3]
// Output: 6
// Explanation: The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 = 6.

//Here also we are appying post order traversal for finding the sum of nodes in the path and detail explanation done in notebook.

//TC - 0(N)
//SC -O(N)
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

    int ans=INT_MIN;
    int helper(TreeNode* root)
    {
        if(root==NULL)//Edge case
        {
            return 0;
        }
        int l=helper(root->left); //Left call
        int r=helper(root->right); //right call
        if(l<0) //If left value is negative no need to take put 0
        {
            l=0;
        }
        if(r<0) //If right value is negative no need to take put 0
        {
            r=0;
        }
        ans=max(ans,root->val+ l + r); //updating max by calculating the sum of nodes of 1 path
        return root->val + max(l,r);  //Optimising as we are only taking max from left or right in our chosen path so that we can get max path sum.


    }
    int maxPathSum(TreeNode* root) {
        helper(root);
        return ans;
        
         
    }
};