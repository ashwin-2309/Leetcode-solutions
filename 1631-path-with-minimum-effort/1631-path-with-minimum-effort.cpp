class Solution {
public:
    bool isValid( vector<vector<int>> &heights,int mx)
    {
        int dx[4] = {0,0,-1,1};
        int dy[4] = {1,-1,0,0}; 
        int n = heights.size();
        int m = heights[0].size(); 
        queue<pair<int,int>> q;
        q.push({0,0});
        vector<vector<int>> vis(n,vector<int>(m,0));
        vis[0][0] = 1;
        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if(x == n-1 and y == m-1)return true;
            for(int i=0;i<4;i++){
                 int newX = x+dx[i],newY = y+dy[i];
                if(newX>=0 and newY>=0 and newX < n and newY < m and !vis[newX][newY])
                {
                    if( abs(heights[x][y] - heights[newX][newY])<=mx)
                    {
                        vis[newX][newY] = 1;
                        q.push({newX,newY});
                    }
                }
            }
        }
        return false;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int s = 0,e = 1e6,ans = 1e6;
        while(s<=e)
        {
            int mid = s+(e-s)/2;
            if(isValid(heights,mid) == true)
            {
                ans = mid,ans;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return ans;
    }
};