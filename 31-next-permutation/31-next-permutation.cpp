class Solution {
public:
    void nextPermutation(vector<int>& nums) {
//         find the last point where a[i] < a[i+1]
//         if there is none then return the array
//         if there is then from that index go from the back and swap with the element that is just bigger than it
        
        int index = -1;
        int n = nums.size();
        for(int i=0;i<n-1;i++){
             if(nums[i] < nums[i+1])
                 index = i;
        }
//         edge case
        if(index == -1)
        {
            reverse(nums.begin(),nums.end());
            return;
        }
//         now the swapping part
        for(int i=n-1;i>index;i--){
            if(nums[i] > nums[index])
            {
                swap(nums[i],nums[index]);
                break;
            }
        }
//         now the sorting or reversing part
        reverse(nums.begin()+index+1,nums.end());
        return;
    }
};