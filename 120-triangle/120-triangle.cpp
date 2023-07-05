class Solution {
public:
    int helper(int vectorNo,int prevIdx, vector<vector<int>> &a, vector<vector<int>> &dp)
    {
//         we are going from start to end
//         base case
        if(vectorNo == a.size())
        {
            return 0;
        }
        
        // int sizeAllowed = a[vectorNo].size();
// //         curr size allowed
        
        if(dp[vectorNo][prevIdx] != -1)return dp[vectorNo][prevIdx];
//         taking the current thing
        int noStep = a[vectorNo][prevIdx] + helper(vectorNo+1,prevIdx,a,dp);
        
//         I can always take the next step as this vectorSize is always greater than the previous one
        int step = a[vectorNo][prevIdx+1] + helper(vectorNo+1,prevIdx+1,a,dp);
        
        return dp[vectorNo][prevIdx] = min(noStep,step);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
         vector<vector<int>> dp(300,vector<int>(300,-1));
        return triangle[0][0] + helper(1,0,triangle,dp);
    }
};