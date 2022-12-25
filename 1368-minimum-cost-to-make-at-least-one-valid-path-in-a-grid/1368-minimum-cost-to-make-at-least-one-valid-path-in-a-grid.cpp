class Solution {
public:
    int minCost(vector<vector<int>>& c) {
        int n = c.size();
        int m = c[0].size(); 
    
        deque<pair<int,vector<int>>> dq;
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        int dx[4] = {0,0,-1,1};
        int dy[4] = {1,-1,0,0}; 
        string dir = "1243";
        dist[0][0] = 0;
        dq.push_front({0,{0,0}});
        while(!dq.empty()) {  
            // get the front element from the deque
            auto temp = dq.front();
            int x = temp.second[0];
            int y = temp.second[1];
            int cost = temp.first;
            dq.pop_front();
            if(x==n-1 and y==m-1) return dist[x][y];
            // iterate through the four possible directions
            for(int i=0; i<4; i++) {
                int newCost = cost;
                // if the current direction is different from the direction specified in the input matrix
                if(dir[i]-'0' != c[x][y]) {
                    // increase the cost by 1
                    newCost++;
                }
                int newX = x + dx[i];
                int newY = y + dy[i];
                // check if the new position is within the boundaries of the matrix and 
                // if the new cost is less than the current cost stored in the dist array
                if(newX >= 0 and newY >= 0 and newX < n and newY < m and newCost < dist[newX][newY]) {
                    // if the new cost is not equal to the current cost, push it to the back of the deque
                    if(newCost != cost) {
                        dq.push_back({newCost,{newX,newY}});
                    } 
                    // otherwise, push it to the front of the deque
                    else {
                        dq.push_front({newCost,{newX,newY}});
                    }
                    // update the cost in the dist array
                    dist[newX][newY] = newCost;
                }
            }
        }
        // return -1 if it is not possible to reach the destination
        return -1;
    }
};
