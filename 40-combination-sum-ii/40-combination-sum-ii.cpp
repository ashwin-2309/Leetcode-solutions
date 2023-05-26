class Solution {
public:
    
    void helper( vector<vector<int>> &ans, vector<int> &a,vector<int> &curr, int target,int index)
    {
        if(target == 0)
        {
            ans.push_back(curr);
            return;
        }
        
        for(int i = index;i<a.size();i++)
        {
            if(i> index and a[i] == a[i-1])
                continue;
            
            if(a[i] > target)break;
            
            curr.push_back(a[i]);
            
            helper(ans,a,curr,target-a[i],i+1);
            
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
         vector<vector<int>> ans;
        vector<int> curr;
        int index = 0;
        
        helper(ans,candidates,curr,target,index);
        return ans;
    }
};