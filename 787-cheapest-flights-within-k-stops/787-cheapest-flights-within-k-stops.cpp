class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //no need for dijkstra as the stops are increasing by 1 at a time so normal bfs with distance normalization will suffice
        vector<pair<int,int>> adj[n];
        //{{1,2,3},{4,5,6},{7,8,9}}
        for(auto it: flights)
        {
            adj[it[0]].push_back({it[1],it[2]});
        }
        queue<pair<int,pair<int,int>>> q;
        vector<int> dist(n,1e9);
        dist[src] = 0;
        // stops,node,cost
        q.push({0,{src,0}});
        while(!q.empty())
        {
            auto temp = q.front();
            int stops = temp.first;
            int node = temp.second.first;
            int cost = temp.second.second;
            q.pop();
            if(stops > k)continue;
            for(auto iter : adj[node])
            {
                int adjNode = iter.first;
                int edW = iter.second;
                if(cost + edW < dist[adjNode] and stops <=k)
                {
                    dist[adjNode] = cost+edW;
                    q.push({stops+1,{adjNode,cost+edW}});
                }
            }
        }
        if(dist[dst] == 1e9)return -1;
        return dist[dst];
    }
};