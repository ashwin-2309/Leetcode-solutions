class Solution {
public:
//     vector method
     vector<vector<int>> methodOne( vector<vector<int>> &intervals)
     {
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
    
     vector<vector<int>> methodTwo( vector<vector<int>> &intervals)
     {
         vector<vector<int>> res;
         int n = intervals.size();
         sort(intervals.begin(),intervals.end());
         
//          we will use stack here
         stack<vector<int>> st;
         st.push({intervals[0][0],intervals[0][1]});
         
         for(int i=1;i<n;i++){
              if(st.top()[1] >= intervals[i][0])
              {
                  st.top()[1] = max(st.top()[1] , intervals[i][1]);
              }
             else{
                 st.push({intervals[i]});
             }
         }
         while(!st.empty())
         {
             res.push_back(st.top());
             st.pop();
         }
         reverse(res.begin(),res.end());
         
         return res;
     }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
         return methodTwo(intervals);
    }
};