class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
         vector<vector<int>> res;
        
         sort(intervals.begin(),intervals.end());
        
         res.push_back(intervals[0]);;
        
         int n = intervals.size();
        
         for(int i=1 ;i < n;i++)
         {
// check the back element in res and if its 2nd element is greater than the first element of intervals then merge
             
             int back = res.back()[1];
             if(back >= intervals[i][0]){
                 res.back()[1] = max(res.back()[1],intervals[i][1]);
             }
             else{
                 res.push_back(intervals[i]);
             }
         }
        return res;
        
    }
};