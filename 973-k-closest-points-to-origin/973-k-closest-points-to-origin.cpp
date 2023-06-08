class Solution {
public:
    int distance(int x,int y)
    {
        return (x*x + y*y);
    } 
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
         vector<vector<int>> ans;
        priority_queue<pair<int,int>> pq;
        
        int n = points.size();
//             pq will contain distance of the points and the index of that point in the vector
//         max Heap so min elements will be at the bottom
        for(int i=0;i<n;i++)
        {
            int dist = distance(points[i][0],points[i][1]);
            
            pq.push({dist,i});            
            if(pq.size() > k)pq.pop();
        }
        
        while(!pq.empty())
        {
            auto index = pq.top().second;
            pq.pop();
            int x = points[index][0];
            int y = points[index][1];
                                  
            
            ans.push_back({x,y});;
        }
        
        return ans;
    }
};