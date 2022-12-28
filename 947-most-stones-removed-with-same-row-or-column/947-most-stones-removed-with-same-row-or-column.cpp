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
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        //first by dsu
        //rows and columns as nodes (can be useful in bfs also)
        //rows from
         unordered_map<int,int> stoneNodes;
        int maxRow = 0,maxCol = 0;
        for(auto i : stones)
        {
            int x = i[0],y=i[1];
            maxRow = max(maxRow,x);
            maxCol = max(maxCol,y);
        }
        dsu d(maxRow+maxCol+1);
        //rows = 0 to n-1 and columns = n to n+m-1
        for(auto i : stones)
        {
            int x = i[0],y=i[1]+maxRow+1;
            if(d.findPar(x) != d.findPar(y))
            {
                   d.unionBySize(x,y);
            }
            stoneNodes[x] = 1;
            stoneNodes[y] = 1;
        }
        //find no. of components;
        int totalStones = stones.size();
        int component = 0;
        
        for(auto it : stoneNodes)
        {
            if(d.findPar(it.first) == it.first)component++;
        }
        int ans = totalStones - component;
        return ans;
    }
};