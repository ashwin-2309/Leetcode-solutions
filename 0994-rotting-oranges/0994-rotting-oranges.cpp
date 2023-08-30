class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int dx[4] = {0,0,-1,1};
        int dy[4] = {1,-1,0,0}; 
        int n = grid.size();
        int m= grid[0].size();
        int freshCount = 0;
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
               for(int j=0;j<m;j++){
                   if(grid[i][j] == 1)
                       freshCount++;
                   else if(grid[i][j] == 2)
                   {
                       q.push({i,j});
                   }
               }
        }
        if(freshCount == 0)return 0;
        
        int time = -1;
        while(!q.empty())
        {
            int sz = q.size();
            time++;
            while(sz--)
            {

                auto x = q.front().first;
                auto y = q.front().second;
                q.pop();
                
                for(int k=0;k<4;k++)
                {
                    int newX = x+dx[k];
                    int newY = y+dy[k];
                    
                    if(newX<n and newY < m and newX >=0 and newY >=0 and grid[newX][newY] == 1)
                    {
                        grid[newX][newY] = 2;
                        q.push({newX,newY});
                        freshCount--;
                    }
                }
                
            }
        }
        if(freshCount == 0)
            return time;
        return -1;
    }
};