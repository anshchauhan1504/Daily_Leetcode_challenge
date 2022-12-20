// 938. Range Sum of BST
// Given the root node of a binary search tree and two integers low and high, return the sum of values of all nodes with a value in the inclusive range [low, high].
// Example 1:
// Input: root = [10,5,15,3,7,null,18], low = 7, high = 15
// Output: 32
// Explanation: Nodes 7, 10, and 15 are in the range [7, 15]. 7 + 10 + 15 = 32.

// TC = O(N)
// SC = O(N)
//You have to make mostly 3 cases in this question 
#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum=0;
        if(root==NULL)//edge case
        {
            return 0;
        }
        if(low<=root->val && root->val<=high)//checking whether root data lies in this range if it is then add in the sum and call to left whatever the result add to sum and call to right whatever the result add to sum.
        {
            sum+=root->val + rangeSumBST(root->left,low,high) + rangeSumBST(root->right,low,high);
        }
        else if(root->val<low)//if this is the cond then no need to check left as all the elements to the left of root data will be smaller than low.
        {
            return rangeSumBST(root->right,low,high);
        }
        else if(root->val>high)//if this is the cond then no need to check right as all the elements to the right of root data will be larger than high.
        {
            return rangeSumBST(root->left,low,high);
        }
        return sum;
   
    }
};
int main(){
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);

return 0;
}

