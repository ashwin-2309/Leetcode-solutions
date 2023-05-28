class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& a) {
        sort(a.begin(),a.end());
         vector<vector<int>> ans;
        ans.push_back(a[0]);
        for(int i=1;i<a.size();i++)
        {
            int lastStart = ans.back()[0],lastEnd = ans.back()[1];
            int currStart = a[i][0],currEnd = a[i][1];
            
            if(lastEnd >= currStart)
            {
                ans.back()[1] = max(lastEnd,currEnd);
            }
            else{
                ans.push_back(a[i]);
            }
        }
        return ans;
    }
};