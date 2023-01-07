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
    vector<int> bfs(TreeNode* root)
    {
        vector<int> ans;
        //we will use bfs technique and push the last node
        if(root == NULL)return ans;
        queue<TreeNode*> q;
        q.push(root);
        //doing the level order traversal and pushing the last element
        while(!q.empty())
        {
            int n = q.size();
            while(n--)
            {
                auto node = q.front();
                q.pop();
                if(n == 0)ans.push_back(node->val);
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }  
            
        }
        return ans;
    }
    void dfsHelper(TreeNode* node,int level,vector<int> &ans)
    { 
        if(node == NULL)return;
        if(level == ans.size())ans.push_back(node->val);
        dfsHelper(node->right,level+1,ans);
        dfsHelper(node->left,level+1,ans);
    }
    vector<int> dfs(TreeNode* root)
    {
        vector<int> ans;
        dfsHelper(root,0,ans);
        return ans;
    }
    vector<int> rightSideView(TreeNode* root) {
        //Can be done using both bfs and dfs
        return dfs(root);
    }
};