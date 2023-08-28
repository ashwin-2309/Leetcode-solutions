class Solution {
public:
    int numIslands(vector<vector<char>>& a) {
        int ans = 0;
        int dx[4] = {-1,1,0,0};
        int dy[4] = {0,0,-1,1};
        
        int n = a.size(); 
        int m = a[0].size(); 
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(a[i][j] == '1')
                {
                    ans++;
//                     do dfs here
                    stack<pair<int,int>> s;
                    s.push({i,j});
                    while(!s.empty()){
                        auto temp = s.top();
                        s.pop();
                        
                        int newX,newY;
                        for(int k=0;k<4;k++)
                        {
                            newX = temp.first + dx[k],newY=temp.second+dy[k];
                            if(newX >= 0 and newX < n and newY >=0 and newY < m and a[newX][newY] == '1')
                            {
                                s.push({newX,newY});
//                                 marking it as visited
                                a[newX][newY] = '2';
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};