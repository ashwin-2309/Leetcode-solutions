class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        // Initialize the priority queue and visited array
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid.size(), false));
        // Push the starting point into the queue
        pq.push({grid[0][0], 0});
        visited[0][0] = true;
        // Initialize the directions array
        int dx[4] = {0, 0, -1, 1};
        int dy[4] = {1, -1, 0, 0};
        int ans = 0;
        // Loop until the priority queue is not empty
        while (!pq.empty()) {
            auto node = pq.top();
            pq.pop();
            int cost = node.first;
            int x = node.second / grid.size();
            int y = node.second % grid.size();
            ans = max(ans, cost);
            if (x == grid.size() - 1 && y == grid.size() - 1) {
                // If we have reached the destination, return the result
                return ans;
            }
            // Explore all 4-directionally adjacent squares
            for (int i = 0; i < 4; i++) {
                int newX = x + dx[i];
                int newY = y + dy[i];
                if (newX >= 0 && newY >= 0 && newX < grid.size() && newY < grid.size() && !visited[newX][newY]) {
                    visited[newX][newY] = true;
                    int newCost = max(cost, grid[newX][newY]);
                    pq.push({newCost, newX * grid.size() + newY});
                }
            }
        }
        return ans;
    }
};
