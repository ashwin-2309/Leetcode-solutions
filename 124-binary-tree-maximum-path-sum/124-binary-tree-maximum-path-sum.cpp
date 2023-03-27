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
        if(!node){
            return 0;
        }
//         if elements in left or right part are negative don't consider them
        int leftSum = max(0,helper(node->left,mx));
        int rightSum = max(0,helper(node->right,mx));
        int maxSumAtThisRoot = leftSum+rightSum+node->val;
        mx = max(mx,maxSumAtThisRoot);
//         now we want to move up so along with root what should we include,left part or right part
//         obviously that one that is maximum between them
        int partToReturn = max(leftSum,rightSum)+node->val;
        return partToReturn;
    }
    int maxPathSum(TreeNode* root) {
        if(!root)return 0;
        int mx = root->val;
        int ans = helper(root,mx);
        return mx;
    }
};