class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n - 2; i++) {
            int s = nums[i];
            int m = i + 1, e = n - 1;
            
            while (m < e) {
                int sum = s + nums[m] + nums[e];
                if (sum == 0) {
                    ans.push_back({s, nums[m], nums[e]});
                    m++;
                    e--;
                    while (m < e && nums[m] == nums[m-1]) m++;  // skip duplicates
                    while (m < e && nums[e] == nums[e+1]) e--;  // skip duplicates
                } 
                
                else if (sum > 0) {
                    e--;
                }
                
                else {
                    m++;
                }
            }
            while (i < n-2 && nums[i] == nums[i+1]) i++;  // skip duplicates
        }
        
        return ans;
    }
};
