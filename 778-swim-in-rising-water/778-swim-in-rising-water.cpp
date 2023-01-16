class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        //find the path with minimum 
        //we will use dijkstra but instead of storing distance we will store the max node in the path
        priority_queue<pair<int,vector<int>>,vector<pair<int,vector<int>>>,greater<pair<int,vector<int>>>>  pq; 
        int n = grid.size();
        pq.push({grid[0][0],{0,0}});
         vector<vector<bool>> vis(n,vector<bool>(n,false));
        vis[0][0] = true;
        int dx[4] = {0,0,-1,1};
        int dy[4] = {1,-1,0,0}; 
        int ans = 0;
        while(!pq.empty())
        {
            auto node = pq.top();
            auto cost = node.first;
            auto x = node.second[0];
            auto y = node.second[1];
            pq.pop();
            if(x==n-1 and y == n-1)return cost;
            for(int i=0;i<4;i++){
                 int newX = x+dx[i],newY=y+dy[i];
                 if(newX>=0 and newY >=0 and newX<n and newY<n and vis[newX][newY] == false)
                 {
                    vis[newX][newY] = true;
                    int newCost = max(cost,grid[newX][newY]);
                    pq.push({newCost,{newX,newY}});
                 }
            }
            
        }
        return ans;
    }
};