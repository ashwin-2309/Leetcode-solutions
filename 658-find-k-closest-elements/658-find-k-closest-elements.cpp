class Solution {
public:
    vector<int> findClosestElements(vector<int>& a, int k, int x) {
        vector<int> ans;
        
//         we will create a priority queue for max Heap as the min elements will be down and we  need them
        priority_queue<pair<int,int>> pq;
        
        for(auto &i : a){
             pq.push({abs(i-x),i});
            if(pq.size() > k)pq.pop();
        }
        
//         now our pq is left with the things we require
        while(!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
     }
};