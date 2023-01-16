class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int sum = 0;int digitSum = 0;
        for(auto i : nums)
            sum+=i;
        for(auto j : nums)
        {
            while(j!=0){
                digitSum+=j%10;
                j/=10;
            }
        }
        return abs(digitSum - sum);
    }
};