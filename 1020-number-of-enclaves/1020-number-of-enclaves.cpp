class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
//         what we have to do is find the number of 1's that are not on the boundary or connected to the boundary
//         so insert all the elements that are 1 and are on the boundary in the queue and convert those 1's to 2
//         and then check the no. of 1's that are present
        queue<pair<int,int>> q;
        int n=grid.size(),m=grid[0].size();
        
        
       for(int i=0;i<n;i++){
            if(grid[i][0] == 1)q.push({i,0});
           if(grid[i][m-1] == 1)q.push({i,m-1});
       }
        
        for(int i=0;i<m;i++){
            if(grid[0][i] == 1)q.push({0,i});
            if(grid[n-1][i] == 1)q.push({n-1,i});
        }
        
        int dx[4] = {0,0,-1,1};
        int dy[4] = {1,-1,0,0}; 
        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            grid[x][y] = 2;
            for(int i=0;i<4;i++)
            {
                int newX = x+dx[i];
                int newY = y+dy[i];
                if(newX >=0 and newX<n and newY>=0 and newY<m and grid[newX][newY] == 1)
                {
                    q.push({newX,newY});
                    grid[newX][newY] = 2;
                }
            }
            
        }
        int ans = 0;
        for(int i=0;i<n;i++){
               for(int j=0;j<m;j++){
                   if(grid[i][j] == 1)ans++;
               }
        }
        return ans;
    }
};