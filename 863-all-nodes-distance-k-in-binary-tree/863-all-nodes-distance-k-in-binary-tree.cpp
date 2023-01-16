/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void buildParent(TreeNode* root,TreeNode* target, unordered_map<TreeNode*,TreeNode*> &parent)
    {
        if(root == NULL)
        {
            parent[root] = NULL;
            return;
        }
        if(root->left)parent[root->left] = root;
        if(root->right)parent[root->right]=root;
        buildParent(root->left,target,parent);
        buildParent(root->right,target,parent);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        //build the parent part
         unordered_map<TreeNode*,TreeNode*> parent;
         buildParent(root,target,parent);
         parent[root] = NULL;
        //now we will do bfs with vis array
        int vis[501] = {0};
        queue<TreeNode*> q; 
        q.push(target);
        vis[target->val] = 1;
        int dist = 0;
        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                if(dist >= k)break;
                auto node = q.front();  
                q.pop();
                if(node->right and vis[node->right->val] == false)
                {
                    q.push(node->right);
                    vis[node->right->val] = 1;
                }
                if(node->left and vis[node->left->val] == false)
                {
                    q.push(node->left);
                    vis[node->left->val] = 1;
                }
                if(parent[node] != NULL and vis[parent[node]->val] == false){
                    q.push(parent[node]);
                    vis[parent[node]->val] = 1;
                }
            }
            if(dist == k)break;
            dist++;
        }
        vector<int> ans;
        while(!q.empty())
        {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};