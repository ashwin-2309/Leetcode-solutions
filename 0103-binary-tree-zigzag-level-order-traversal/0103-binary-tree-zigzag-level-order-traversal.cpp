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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
         vector<vector<int>> ans;
        if(root == NULL)return ans;
        queue<TreeNode*> q;
        q.push(root);
        bool level = 0;
        
        while(!q.empty())
        {
            int sz = q.size();
            vector<int> curr(sz);
            for(int i=0;i<sz;i++)
            {
                auto temp = q.front();
                q.pop();
                if(level == 0)
                {
                    curr[i] = temp->val;
                }
                else{
                    curr[sz-i-1] = temp->val;
                }
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            ans.push_back(curr);
            level = !level;
        }
        return ans;
    }
};