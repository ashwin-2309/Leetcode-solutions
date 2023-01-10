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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>> > m;
        // x , y , values in sorted order
        queue<pair<TreeNode*,pair<int,int>>> q;
        // Node , x, y
         vector<vector<int>> ans;
        if(root == NULL)return ans;
        q.push({root,{0,0}});
        while(!q.empty())
        {
            auto temp = q.front().first;
            int x = q.front().second.first;
            int y= q.front().second.second;
            m[x][y].insert(temp->val);
            q.pop();
            if(temp->left)q.push({temp->left,{x-1,y+1}});
            if(temp->right)q.push({temp->right,{x+1,y+1}});
        }
        for(auto i : m)
        {
            vector<int> col;
            for(auto j : i.second)
            {
                auto k = j.second;
                //k is multiset
                for(auto l = k.begin();l!=k.end();l++)
                {
                    col.push_back(*l);
                }
            }
            ans.push_back(col);
        }
        return ans;
    }
};