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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
//         first create the parent thingy in this
        unordered_map<TreeNode*,TreeNode*> parent;
        unordered_map<TreeNode*,bool> vis;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            auto node = q.front();
            q.pop();
            
            if(node->left)
            {
                parent[node->left] = node;
                q.push(node->left);
            }
            if(node->right)
            {
                parent[node->right] = node;
                q.push(node->right);
            }
        }
        
//     parents have been marked and at this point queue is empty
        
        q.push(target);
        vis[target] = true;
        int currLevel = 0;
        
        while(!q.empty())
        {
            int size = q.size();
            if(currLevel++ == k)break;
            
            for(int i=0;i <size;i++)
            {
                TreeNode* node = q.front();
                q.pop();
                
                if(node->left and vis[node->left] == false)
                {
                    q.push(node->left);
                    vis[node->left] = true;
                }
                if(node->right and vis[node->right] == false)
                {
                    q.push(node->right);
                    vis[node->right] = true;
                }
                
                if(parent[node] and vis[parent[node]] == false)
                {
                    q.push(parent[node]);
                    vis[parent[node]] = true;
                }
                
            }
        }
        
        vector<int> ans;
        while(!q.empty())
        {
            TreeNode* node= q.front();
            q.pop();
            ans.push_back(node->val);
        }
        
        return ans; 
        
    }
};