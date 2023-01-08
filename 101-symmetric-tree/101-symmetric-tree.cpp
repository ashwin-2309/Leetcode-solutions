/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool helper(TreeNode* p,TreeNode* q)
    {
        if(p == NULL and q== NULL)return true;
        else if(!p or !q)return false;
        if(p->val != q->val)return false;
        else return helper(p->left,q->right) and helper(p->right,q->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)return true;
        return helper(root,root);
    }
};