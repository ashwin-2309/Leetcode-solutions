class dsu
{
    public:
    vector<int> parent, size;
    dsu(int n)
    {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }
    int findPar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findPar(parent[node]);
    }
    void unionBySize(int u, int v)
    {
        int ulp_u = findPar(u);
        int ulp_v = findPar(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
}; 

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        //create dsu and intialize it and connect the connected ones
        int dx[4] = {0,0,-1,1};
        int dy[4] = {1,-1,0,0}; 
        int n = grid.size();
        dsu d(n*n);
        for(int i=0;i<n;i++){
               for(int j=0;j<n;j++){
                    if(grid[i][j] == 1)
                    {
                        for(int k=0;k<4;k++)
                        {
                            int newX = i+dx[k];
                            int newY = j+dy[k];
                            if(newX>=0 and newY>=0 and newX<n and newY<n and grid[newX][newY] == 1)
                            {
                                int nodeNo = i*n+j;
                                int adjNodeNo = newX*n + newY;
                                d.unionBySize(nodeNo,adjNodeNo);
                            }
                        }
                    }
               }
        }
        int mx = 0;
        for(int i=0;i<n;i++){
               for(int j=0;j<n;j++){
                   if(grid[i][j] == 0)
                   {
                      set<int> components;
                       for(int k=0;k<4;k++){ 
                           int newX=i+dx[k];
                           int newY = j+dy[k];
                           if(newX>=0 and newY>=0 and newX<n and newY<n and grid[newX][newY] == 1)
                           {
                               components.insert(d.findPar(newX*n+newY));
                           }
                       }
                       int sizeTotal = 0;
                       for(auto it : components)
                       {
                           sizeTotal += d.size[it];
                       }
                       mx = max(mx,sizeTotal+1);
                   }
               }
        }
        for(int i=0;i<n*n;i++){
             mx = max(mx,d.size[d.findPar(i)]);
        }
        return mx;
    }
};