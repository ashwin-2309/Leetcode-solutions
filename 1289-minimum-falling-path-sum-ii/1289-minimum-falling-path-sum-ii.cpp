class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();

        // Initialize the dp matrix with the values from the first row
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for (int j = 0; j < m; j++) {
            dp[0][j] = arr[0][j];
        }

        // Iterate through the remaining rows
        for (int i = 1; i < n; i++) {
            // Find the minimum and second minimum values in the previous row
            int minVal = INT_MAX;
            int secondMinVal = INT_MAX;
            int minIndex = -1;

            for (int j = 0; j < m; j++) {
                if (dp[i - 1][j] < minVal) {
                    secondMinVal = minVal;
                    minVal = dp[i - 1][j];
                    minIndex = j;
                } else if (dp[i - 1][j] < secondMinVal) {
                    secondMinVal = dp[i - 1][j];
                }
            }

            // Calculate the minimum path sum for the current row
            for (int j = 0; j < m; j++) {
                if (j != minIndex) {
                    dp[i][j] = arr[i][j] + minVal;
                } else {
                    dp[i][j] = arr[i][j] + secondMinVal;
                }
            }
        }

        // Find the minimum path sum in the last row
        int minSum = INT_MAX;
        for (int j = 0; j < m; j++) {
            if (dp[n - 1][j] < minSum) {
                minSum = dp[n - 1][j];
            }
        }

        return minSum;
    }
};
