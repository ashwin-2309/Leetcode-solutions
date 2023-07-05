class Solution {
public:
    int helper(int row,int col, vector<vector<int>> &grid, vector<vector<int>> &dp)
    {
        if(row == 0 and col == 0)
        {
            return grid[0][0];
        }
        if(row < 0 or col < 0)return 1e9;
        
        if(dp[row][col] != -1)return dp[row][col];
        
        int leftStep = grid[row][col] + helper(row,col-1,grid,dp);
        int upStep = grid[row][col] + helper(row-1,col,grid,dp);
        
        return dp[row][col] = min(leftStep,upStep);
    }
    int minPathSum(vector<vector<int>>& grid) {
         vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),-1));
        return helper(grid.size()-1,grid[0].size()-1,grid,dp);
    }
};