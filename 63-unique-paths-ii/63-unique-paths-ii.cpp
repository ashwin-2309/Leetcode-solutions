class Solution {
public:
    int helper(int row,int col, vector<vector<int>> &a, vector<vector<int>> &dp)
    {
        if(row < 0 or col<0 or a[row][col] == 1)return 0;
        if(row == 0 and col == 0)return 1;
        
        if(dp[row][col] != -1)return dp[row][col];
        int up = helper(row-1,col,a,dp);
        int left = helper(row,col-1,a,dp);
        
        return dp[row][col] = up + left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0] == 1)return 0;
        int rows = obstacleGrid.size(),cols = obstacleGrid[0].size();
         vector<vector<int>> dp(rows,vector<int>(cols,-1));
        return helper(rows-1,cols-1,obstacleGrid,dp);
    }
};