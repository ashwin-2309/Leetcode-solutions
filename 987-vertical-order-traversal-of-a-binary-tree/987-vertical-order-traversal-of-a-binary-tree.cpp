class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // Map to store the x, y coordinates and the values of nodes 
        map<int, map<int, multiset<int>>> coordinatesToValues;

        // Queue to store current node, x, and y coordinates
        queue<pair<TreeNode*, pair<int, int>>> bfsQueue;

        // Vector to store final answer
        vector<vector<int>> verticalOrder;

        if (root == nullptr) return verticalOrder; // Empty case

        bfsQueue.push({root, {0, 0}});

        // Perform a breadth-first search
        while (!bfsQueue.empty()) {
            auto currentNode = bfsQueue.front().first;
            int x = bfsQueue.front().second.first;
            int y = bfsQueue.front().second.second;
            // Insert current node value into the map 
            coordinatesToValues[x][y].insert(currentNode->val);
            bfsQueue.pop();

            if (currentNode->left) bfsQueue.push({currentNode->left, {x - 1, y + 1}});
            if (currentNode->right) bfsQueue.push({currentNode->right, {x + 1, y + 1}});
        }
        //Iterate over the map and add the values to the answer vector
        for (auto &[x, columns]: coordinatesToValues) {
            vector<int> columnValues;
            for (auto &[y, values]: columns) {
                // Add the values at this x, y coordinate to the answer vector
                for (auto val: values) {
                    columnValues.push_back(val);
                }
            }
            verticalOrder.push_back(columnValues);
        }

        return verticalOrder;
    }
};
