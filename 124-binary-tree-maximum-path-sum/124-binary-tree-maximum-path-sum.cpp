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
    int helper(TreeNode* node,int &mx)
    {
        if(node == NULL)return 0;
        int leftSum = max(0,helper(node->left,mx));
        int rightSum = max(0,helper(node->right,mx));
        int sumThroughNode =leftSum+rightSum+node->val;
        mx = max(mx,sumThroughNode);
        return max(leftSum,rightSum)+node->val;
    }
    int maxPathSum(TreeNode* root) {
        if(root == NULL)return 0;
        int mx = INT_MIN;
        int ans = helper(root,mx);
        return mx;
    }
};