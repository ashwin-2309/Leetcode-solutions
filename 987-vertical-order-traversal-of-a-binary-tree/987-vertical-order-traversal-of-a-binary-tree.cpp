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
        // Map to store the nodes in the tree, with the x coordinate as the first key and the y coordinate
        // as the second key. The set stores the values of the nodes.
        map<int, map<int, multiset<int>>> nodes;
        // Queue to store the nodes that need to be processed
        queue<pair<TreeNode*, pair<int, int>>> todo;
        // queue is node,{x,y}
        // Initialize the queue with the root node and the coordinates (0, 0)
        todo.push({root, {0, 0}});
        // Process nodes in the queue until it is empty
        while (!todo.empty()) {
            // Get the next node to process and its coordinates
            auto p = todo.front();
            todo.pop();
            TreeNode* node = p.first;
            int x = p.second.first, y = p.second.second;
            // Insert the value of the node into the map
            nodes[x][y].insert(node -> val);
            // If the node has a left child, add it to the queue along with its coordinates
            if (node -> left) {
                todo.push({node -> left, {x - 1, y + 1}});
            }
            // If the node has a right child, add it to the queue along with its coordinates
            if (node -> right) {
                todo.push({node -> right, {x + 1, y + 1}});
            }
        }
        // Vector to store the values of the nodes in the tree
        vector<vector<int>> ans;
        // Iterate through the map and add the values of the nodes to the vector
        for (auto p : nodes) {
            // Vector to store the values of the nodes in a column
            //this is int , map<int,multiset<int>>
            
            vector<int> col;
            for (auto q : p.second) 
            {
                // Add the values of the nodes in the set to the column vector
                for(auto r : q.second)
                {
                    col.push_back(r);
                }
            }
            // Add the column vector to the answer vector
            ans.push_back(col);
        }
        return ans;
    }
};
