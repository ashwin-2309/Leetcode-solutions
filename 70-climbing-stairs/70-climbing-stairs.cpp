class Solution {
public:
    int helper(int n,vector<int> &dp)
    {
        if(n<0)return 0;
        if(n == 0)
        {
            return 1;
        }
        if(dp[n] != -1)return dp[n];
        
        
        int left = helper(n-1,dp);
        int right = helper(n-2,dp);
        return dp[n] = left + right;
    }
    int tabulation(int n)
    {
        vector<int> dp(n+1,-1);
        dp[0] = 1;
        dp[1] = 1;
        for(int i=2;i<=n;i++)
        {
            dp[i] = dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        // return helper(n,dp);
        return tabulation(n);
    }
};