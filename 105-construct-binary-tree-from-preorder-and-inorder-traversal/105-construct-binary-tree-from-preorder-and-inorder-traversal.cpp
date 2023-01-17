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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
         unordered_map<int,int> inMap;
         int n= inorder.size();
        for(int i=0;i<n;i++){
             inMap[inorder[i]] = i;
        }
        TreeNode* root = x(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,inMap);
        return root;
    }
    TreeNode* x(vector<int> &preorder,int preStart,int preEnd,vector<int> &inorder,int inStart,int inEnd, unordered_map<int,int> &inMap)
    {
        if(preStart > preEnd or inStart > inEnd)return NULL;
        TreeNode* root = new TreeNode(preorder[preStart]);
        int inRoot = inMap[root->val];
        int numsLeft = inRoot - inStart;
        //
        root->left = x(preorder,preStart+1,preStart+numsLeft,inorder,inStart,inRoot-1,inMap);
        root->right = x(preorder,preStart+numsLeft+1,preEnd,inorder,inRoot+1,inEnd,inMap);
        return root;
    }
};