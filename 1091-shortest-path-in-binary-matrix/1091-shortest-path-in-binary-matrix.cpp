class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& a) {
        //no visited matrix
        int n = a.size();
        int m = a[0].size(); 
        if(a[0][0] !=0 or a[n-1][m-1] !=0)return -1;
        int ans = 0;
        queue<pair<int,int>> q;
        a[0][0] = 1;
        q.push({0,0});
        int dx[8] = {0,0,-1,-1,-1,1,1,1};
        int dy[8] = {1,-1,0,1,-1,0,1,-1}; 
        while(!q.empty())
        {
            auto [x,y] = q.front();
            q.pop();
            if(x==n-1 and y==m-1)return a[n-1][m-1];
            for(int i=0;i<8;i++){
                 int newX = x+dx[i],newY = y+dy[i];
                  if(newX>=0 and newY>=0 and newX<n and newY<m and a[newX][newY] == 0)
                  {
                      q.push({newX,newY});
                      a[newX][newY] = 1+a[x][y];
                  }
            }
        }
        return -1;
    }
};