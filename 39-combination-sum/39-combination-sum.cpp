class Solution {
public:
    void helper( vector<vector<int>> &ans,vector<int> &a,vector<int> &curr,int target,int index)
    {
        if(index == a.size())
        {
            if(target == 0)
            {
                ans.push_back(curr);
            }
            return;
        }
//         don't pick
        helper(ans,a,curr,target,index+1);
//         pick
        if(target>=a[index])
        {            
            curr.push_back(a[index]);
            helper(ans,a,curr,target-a[index],index); 
            curr.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
         vector<vector<int>> ans;
        vector<int> curr;
        int index = 0;
        helper(ans,candidates,curr,target,index);
        
        return ans;
    }
};