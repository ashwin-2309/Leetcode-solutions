class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //n = total nodes src = k
        vector<int> dist(n+1,1e9);
        // int dist[n] = 1e9;
        dist[k] = 0;
        vector<pair<int,int>> adj[n+1];
        for(auto i : times)
        {
            adj[i[0]].push_back({i[1],i[2]});
        }
        //adj list created
        //priority queue will contain dist and current node
        set<pair<int,int>> st;
        st.insert({0,k});
        while(!st.empty())
        {
            int dis = (*st.begin()).first;
            int node = (*st.begin()).second;
            st.erase(st.begin());
            for(auto x : adj[node])
            {
                int adjNode = x.first;
                int edgeWeight = x.second;
                int newDis = edgeWeight + dis;
                if(newDis < dist[adjNode])
                {
                    dist[adjNode] = newDis;
                    st.insert({newDis,adjNode});
                }
            }
        }
        int mx = 0;
        for(int i=1;i<n+1;i++){
             mx = max(mx,dist[i]);
        }
        if(mx == 1e9)return -1;
        return mx;
        
    }
};