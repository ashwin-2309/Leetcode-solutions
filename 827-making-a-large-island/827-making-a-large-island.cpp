class Solution {
public:
    // Number of rows in the grid
    int rows;
    // Number of columns in the grid
    int cols;
    // Array to check all 4 directions
    const int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    // Function to perform DFS
    int dfs(vector<vector<int>>& grid, int row, int col, int label, vector<int>& islandSizes) {
        // Base case: if the current index is out of the grid or the value is not 1
        if (row < 0 || row >= rows || col < 0 || col >= cols || grid[row][col] != 1) return 0;
        // Mark the current cell with the current label
        grid[row][col] = label;
        int size = 1;
        // Recursively call dfs on all 4 directions
        for (auto& dir : dirs) {
            size += dfs(grid, row + dir[0], col + dir[1], label, islandSizes);
        }
        // Store the size of the island in the islandSizes array at the index of the label
        islandSizes[label] = size;
        return size;
   
}

int largestIsland(vector<vector<int>>& grid) {
    rows = grid.size();
    cols = grid[0].size();
    int label = 2;
    int maxSize = 0;

    // Array to store the size of each island
    vector<int> islandSizes(rows * cols + 2, 0);

    // First pass: traverse the grid and mark all the connected 1's with the same label
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            if (grid[row][col] == 1) {
                maxSize = max(maxSize, dfs(grid, row, col, label, islandSizes));
                label++;
            }
        }
    }

    // Second pass: traverse the grid again and check for 0's
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            if (grid[row][col] == 0) {
                int size = 1;
                unordered_set<int> labels;
                for (auto& dir : dirs) {
                    int newRow = row + dir[0];
                    int newCol = col + dir[1];
                    if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && grid[newRow][newCol] > 1) {
                        int label = grid[newRow][newCol];
                        if(labels.find(label) == labels.end()){
                            size += islandSizes[label];
                            labels.insert(label);
                        }
                    }
                }
                maxSize = max(maxSize, size);
            }
        }
    }
    return maxSize;
}

};

