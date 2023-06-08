class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        unordered_map<int,int> m;
        for(auto i : nums)
        {
            m[i]++;
        }
        
        vector<int> ans;
        
        for(auto i = m.begin(); i != m.end(); i++)
        {
            pq.push(make_pair(i->second, i->first));
                
            if(pq.size() > k)
            {
                pq.pop();
            }
        }
        
        while(!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
                
        return ans;
    }
};