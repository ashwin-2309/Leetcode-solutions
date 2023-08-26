class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int start = 0,end = nums.size()-1;
        while(start <= end)
        {
            int mid = start + (end-start)/2;
            if(nums[mid] == target)
                return true;
            if(nums[start] < nums[mid])
            {
//                 left portion
                if(target < nums[mid] and target >= nums[start])
                {
                    end = mid-1;
                }
                else
                {
                    start = mid+1;   
                }
            }
            else if(nums[start] > nums[mid])
            {
//                 right portion
                if(target > nums[mid] and target <= nums[end])
                {
                    start = mid+1;
                }
                else
                {
                    end = mid-1;
                }
            }
            else{
                start++;
            }
        }
        return false;
    }
};