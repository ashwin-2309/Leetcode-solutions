class Solution {
public:
    
    vector<int> eventualSafeNodes(vector<vector<int>>& a) {
        //we will first do it by kahn's algo(topo sort)
        //reverse the edges
         int n = a.size();
        vector<int> revadj[n];
         for(int i=0;i<n;i++){
             for(auto j : a[i])
             {
                 revadj[j].push_back(i);
             }
         }
        //reverse adjacency list created now use toposort for this
        vector<int> indegree(n,0);
        for(int i =0;i<n;i++)
        {
            for(auto j : revadj[i])
            {
                indegree[j]++;
            }
        }
        queue<int> q;
        for(int i=0;i<n;i++){
             if(indegree[i] == 0)q.push(i);
        }
        vector<int> ans;
        while(!q.empty())
        {
            int temp = q.front();
            q.pop();
            ans.push_back(temp);
            for(auto neighbour : revadj[temp])
            {
                indegree[neighbour]--;
                if(indegree[neighbour] == 0)q.push(neighbour);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};