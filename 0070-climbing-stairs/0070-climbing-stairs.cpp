class Solution {
public:
    int solve(int n,vector<int> &dp)
    {
        if(n == 0)return 1;
        if(n < 0)return 0;
        
        if(dp[n] != -1)return dp[n];
        
        int stepOne  = solve(n-1,dp);
        int stepTwo = solve(n-2,dp);
        
        return dp[n] = stepOne + stepTwo;
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return solve(n,dp);
    }
};