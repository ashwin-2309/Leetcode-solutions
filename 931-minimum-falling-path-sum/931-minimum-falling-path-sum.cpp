class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Initialize the first row of dp with the values from the matrix
        for (int j = 0; j < n; j++) {
            dp[0][j] = matrix[0][j];
        }

        // Iterate through the matrix from the second row
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = matrix[i][j] + dp[i - 1][j]; // Consider the path from the above cell

                if (j > 0) {
                    dp[i][j] = min(dp[i][j], matrix[i][j] + dp[i - 1][j - 1]); // Consider the path from the above left diagonal cell
                }

                if (j < n - 1) {
                    dp[i][j] = min(dp[i][j], matrix[i][j] + dp[i - 1][j + 1]); // Consider the path from the above right diagonal cell
                }
            }
        }

        // Find the minimum sum in the last row of dp
        int minSum = dp[n - 1][0];
        for (int j = 1; j < n; j++) {
            minSum = min(minSum, dp[n - 1][j]);
        }

        return minSum;
    }
};
