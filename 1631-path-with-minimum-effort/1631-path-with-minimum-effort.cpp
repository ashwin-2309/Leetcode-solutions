class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        //dijkstra algo but effort will be max(curreffort,difference in coordinates)
        //we will use set
        set<pair<int,vector<int>>> st;
        int n = heights.size();
        int m = heights[0].size(); 
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        dist[0][0] = 0;
        int dx[4] = {0,0,-1,1};
        int dy[4] = {1,-1,0,0};
        st.insert({0,{0,0}});
        while(!st.empty())
        {
            auto temp = (*st.begin());
            int x = temp.second[0];
            int y = temp.second[1];
            int currEffort = temp.first;
            if(x == n-1 and y == m-1)
            {
                return currEffort;
            }
            st.erase(st.begin());
            for(int i=0;i<4;i++){
                int newX = x+dx[i];
                int newY = y+dy[i];
                if(newX>=0 and newY>=0 and newX<n and newY<m)
                {
                    int newEffort = max(currEffort,abs(heights[x][y] - heights[newX][newY]));
                    if(newEffort < dist[newX][newY])
                    {
                        dist[newX][newY] = newEffort;
                        st.insert({newEffort,{newX,newY}});
                    }
                }
            }
        }
        return -1;
    }
};