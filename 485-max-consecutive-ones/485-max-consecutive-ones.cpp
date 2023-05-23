class Solution {
public:
   int findMaxConsecutiveOnes(vector<int>& nums) {
        int i=0;
        int maxLen=0;
        int n=nums.size();

        while(i<n){
            if(nums[i]==1){
                int len=0;
                while(i<n&&nums[i]==1){
                    len++;
                    i++;
                }
                maxLen=max(maxLen, len);
            }
            else i++;
        }
        return maxLen;
    }
};