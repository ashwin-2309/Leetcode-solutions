class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int,int> firstTwoSum;
        for(int i:nums1)
        {
            for(int j:nums2)
            {
                firstTwoSum[i+j]++;
            }
        }
        int ans = 0,thirdFourthSum;
        for(int i:nums3)
        {
            for(int j:nums4)
            {
                thirdFourthSum = i + j;
                ans += firstTwoSum[-thirdFourthSum];
            }
        }
        return ans;
    }
};