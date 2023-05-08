class Solution {
public:
    void nextPermutation(vector<int>& nums) {
//         from scratch
//         we have to find the last occurrence of a[i+1] > a[i]
        int index = -1;
        int n = nums.size();
        
//         check for the index
        for(int i=0;i<n-1;i++){
             if(nums[i] < nums[i+1])
             {
                 index = i;
             }
        }
        if(index == -1)
        {
//             the array is sorted in decreasing order
            reverse(nums.begin(),nums.end());
            return;
        }
        
//         now that we have found the index,traverse the array from the back and find the no.which is bigger than the nums[index]
        for(int i=n-1;i>index;i--){
            if(nums[i] > nums[index]){
                swap(nums[i],nums[index]);
                break;
            }  
        }
//         now reverse the no. from index+1 to end
        reverse(nums.begin()+index+1,nums.end());
    }
};