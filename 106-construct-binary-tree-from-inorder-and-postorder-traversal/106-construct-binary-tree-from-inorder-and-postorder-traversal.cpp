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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> inMap;
        int n= inorder.size();
        for(int i=0;i<n;i++)
        {
             inMap[inorder[i]] = i;
        }
        TreeNode* root = x(postorder,0,n-1,inorder,0,n-1,inMap);
        return root;
    }
        TreeNode* x(vector<int> &postorder,int postStart,int postEnd,vector<int> &inorder,int inStart,int inEnd, unordered_map<int,int> &inMap)
    {
        if(postStart > postEnd or inStart > inEnd)return NULL;
        TreeNode* root = new TreeNode(postorder[postEnd]);
        int inRoot = inMap[root->val];
        int numsLeft = inRoot - inStart;
        
        root->left = x(postorder,postStart,postStart+numsLeft-1,inorder,inStart,inRoot-1,inMap);
        root->right = x(postorder,postStart+numsLeft,postEnd-1,inorder,inRoot+1,inEnd,inMap);
        return root;
    }
};