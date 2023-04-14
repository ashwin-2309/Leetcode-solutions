class Solution {
public:
    void help( vector<vector<int>> &ans,vector<int> &nums,vector<int> &curr,int startIndex)
    {
//         base case when startIndex >= size of the nums array
        if(startIndex >= nums.size())
        {
            ans.emplace_back(curr);
            return;
        }
//         include exclude
//         one time include and exclude
        
        help(ans,nums,curr,startIndex+1);

        //         include
        
        curr.emplace_back(nums[startIndex]);
        help(ans,nums,curr,startIndex+1);
        
        curr.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
//         include exclude principle
         vector<vector<int>> ans;
        vector<int> curr;
        int startIndex = 0;
        help(ans,nums,curr,startIndex);
        return ans;
    }
};