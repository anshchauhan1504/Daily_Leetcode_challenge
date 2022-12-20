// 872. Leaf-Similar Trees

// Consider all the leaves of a binary tree, from left to right order, the values of those leaves form a leaf value sequence.
// For example, in the given tree above, the leaf value sequence is (6, 7, 4, 9, 8).
// Two binary trees are considered leaf-similar if their leaf value sequence is the same.
// Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar.
// Example 1:
// Input: root1 = [3,5,1,6,2,9,8,null,null,7,4], root2 = [3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]
// Output: true

// TC = O(N)
// SC = O(N)

// Imp thing in this ques is you must know about leaf node
//  Leaf node = root->left==NULL && root->right==NULL
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
class Solution
{
public:
    void check2(TreeNode *root2, vector<int> &v2)
    {
        if (root2 == NULL)//edge case
        {
            return;
        }
        if (root2->left == NULL && root2->right == NULL)//checking whether leaf or not if it is then insert the val into vector
        {
            v2.push_back(root2->val);
        }
        check2(root2->left, v2);//calling on left 
        check2(root2->right, v2);//calling on right
    }
    void check1(TreeNode *root1, vector<int> &v1)
    {
        if (root1 == NULL)
        {
            return;
        }
        if (root1->left == NULL && root1->right == NULL)
        {
            v1.push_back(root1->val);
        }
        check1(root1->left, v1);
        check1(root1->right, v1);
    }
    bool leafSimilar(TreeNode *root1, TreeNode *root2)
    {
        int cnt = 0;
        vector<int> v1;
        vector<int> v2;
        check1(root1, v1);
        check2(root2, v2);
        if (v1.size() != v2.size())
        {
            return false;
        }
        else
        {

            for (int i = 0; i < v1.size(); i++)
            {
                if (v1[i] == v2[i])
                {
                    cnt += 1;
                }
            }
            return cnt == v1.size();
        }
    }
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    return 0;
}