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
    TreeNode* startNode = NULL;
    void buildParent(TreeNode* node, unordered_map<TreeNode*,TreeNode*> &parent)
    {
        if(node != NULL)
        {
           if(node->left)parent[node->left] = node;
           if(node->right)parent[node->right] = node;
           buildParent(node->left,parent);
           buildParent(node->right,parent);
        }
    }
    void findNode(TreeNode* node,int start)
    {
        if(node)
        {
            if(node->val == start)
            {
                startNode = node;
                return;
            }
            findNode(node->left,start);
            findNode(node->right,start);
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        if(root==NULL)return 0;
        if(root->left == NULL and root->right == NULL)return 0;
        findNode(root,start);
        unordered_map<TreeNode*,TreeNode*> parent; 
        buildParent(root,parent);
        int time = 0;
        queue<TreeNode*> q;
        q.push(startNode);
        unordered_set<TreeNode*> vis; 
        vis.insert(startNode);
        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                auto node = q.front();
                q.pop();
                if(node->left and !vis.count(node->left))
                {
                    q.push(node->left);
                    vis.insert(node->left);
                }
                if(node->right and !vis.count(node->right))
                {
                    q.push(node->right);
                    vis.insert(node->right);
                }
                if(parent[node] and !vis.count(parent[node]))
                {
                    q.push(parent[node]);
                    vis.insert(parent[node]);
                }
            }
            time++;
        }
        return time-1;
    }
};








