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
    int solver(TreeNode* node,int &maxSum)
    {
        if(node == NULL)return 0;
        int leftSum = max(0,solver(node->left,maxSum));
        int rightSum = max(0,solver(node->right,maxSum));
        
        maxSum = max(maxSum,node->val+leftSum+rightSum);
        
        int maxToPropogate = max(leftSum,rightSum);
        return node->val + maxToPropogate;
    }
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        int ans = solver(root,maxSum);
        return maxSum;
    }
};