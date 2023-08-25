class Solution {
public:
    int findMin(vector<int>& nums) {
//        using binary search and doing everything like neetcode
        int start = 0,end = nums.size()-1;
        int globalMin = nums[0];
        while(start <= end)
        {
            int mid = start + (end - start)/2;
//          check if it is in the left sorted part
            if(nums[mid] >= nums[start])
            {
                globalMin = min(globalMin,nums[start]);
                start = mid+1;
            }
            else{
                globalMin = min(globalMin,nums[mid]);
                end = mid-1;
            }
        }
        return globalMin;
    }
};