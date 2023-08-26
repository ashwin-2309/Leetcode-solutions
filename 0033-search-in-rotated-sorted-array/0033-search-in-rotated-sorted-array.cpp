class Solution {
public:
    int search(vector<int>& nums, int target) {
//         first doing by simple binary search
        int start = 0,end = nums.size()-1;
        while (start <= end)
        {
            int mid = start + (end-start)/2;
            if(nums[mid] == target)
                return mid;
            if(nums[mid] >= nums[start])
            {
//             left sorted portion
                if(target < nums[mid] and target >= nums[start])
                {
//                     it exists in left portion
                       end = mid-1;
                }
                else{
                    start = mid+1;
                }
            }
            else{
                if(target > nums[mid] and target <= nums[end])
                {
                    start = mid+1;
                }
                else{
                    end = mid-1;
                }
            }
        }
        return -1;
    }
};