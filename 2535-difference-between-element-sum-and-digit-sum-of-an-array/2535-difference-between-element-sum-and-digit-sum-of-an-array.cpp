class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int sum = 0;int digitSum = 0;
        for(auto j : nums)
        {
            sum+=j; 
            while(j!=0)
            {
                digitSum+=j%10;
                j/=10;
            }
        }
        return abs(digitSum - sum);
    }
};