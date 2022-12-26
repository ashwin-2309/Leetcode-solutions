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
    int findUPar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }
    void unionBySize(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        dsu ds(n);
        int extraEdges = 0;
        for(auto i : connections)
        {
            int u = i[0],v=i[1];
            if(ds.findUPar(u) != ds.findUPar(v))
            {
                ds.unionBySize(u,v);
            }
            else{
                extraEdges++;
            }
        }
        int count = 0;
        for(int i=0;i<n;i++){
             if(ds.parent[i] == i)count++;
        }
        int ans = count-1;
        if(extraEdges >= ans)return ans;
        return -1;
    }
};