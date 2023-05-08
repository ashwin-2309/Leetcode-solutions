class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        int ans = 0;
        for(auto &i : nums)s.insert(i);
        
        for(auto &num : nums)
        {
            if(s.count(num-1) == 0){
//                 prev element of num shouldn't exist in set,then only we start counting
                int currentNum = num;
                int currentStreak = 1;
                
                while(s.count(currentNum+1)){
                    currentNum++;currentStreak++;
                }
                ans = max(ans,currentStreak);
            }
        }
        return ans;
    }
};