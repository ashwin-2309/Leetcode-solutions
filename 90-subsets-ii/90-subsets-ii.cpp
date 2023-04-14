class Solution {
public:

    vector<vector<int>> subsets;
    vector<int> subset;

    void generate(int i, vector<int>& nums){

        if(i == nums.size()){
            subsets.emplace_back(subset);
            return; 
        }

        //1. I choose the current number
        subset.emplace_back(nums[i]);
        generate(i+1,nums);

        subset.pop_back(); //backtracking

        //2. I dont choose the current number [hence I go to the next different number]
        int nextIdx = upper_bound(nums.begin(), nums.end(), nums[i]) - nums.begin();
        
        generate(nextIdx, nums);

        return; 

    }


    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
       sort(nums.begin(), nums.end());
       
       generate(0,nums);

       return subsets;

    }
};