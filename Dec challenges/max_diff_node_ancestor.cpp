// 1026. Maximum Difference Between Node and Ancestor
// Given the root of a binary tree, find the maximum value v for which there exist different nodes a and b where v = |a.val - b.val| and a is an ancestor of b.
// A node a is an ancestor of b if either: any child of a is equal to b or any child of a is an ancestor of b.
// Example 1:
// Input: root = [8,3,10,1,6,null,14,null,null,4,7,13]
// Output: 7
// Explanation: We have various ancestor-node differences, some of which are given below :
// |8 - 3| = 5
// |3 - 7| = 4
// |8 - 1| = 7
// |10 - 13| = 3
// Among all possible differences, the maximum value of 7 is obtained by |8 - 1| = 7.

//In these type of questions generally approach is 
//Tree traversal to find min and max nodes from each path. When reach to leaf node then find difference and return and in last from the difference return from left and right return the max value.

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
    int find_max_diff(TreeNode* root, int maxi, int mini)
    {
        // Base condtion. leaf node end of path.
        if(root==NULL)
        {
            return abs(maxi-mini);
        }
        // Update the max and min
        maxi=max(root->val,maxi);
        mini=min(root->val,mini);
        //Tree traversal
        int left = find_max_diff(root->left,maxi,mini);
        int right = find_max_diff(root->right,maxi,mini);
        //return max value
        return max(left,right);
    }
    int maxAncestorDiff(TreeNode* root) {
        if(root==NULL)
        {
            return 0;
        }
        return find_max_diff(root,root->val,root->val);
 
    }
};