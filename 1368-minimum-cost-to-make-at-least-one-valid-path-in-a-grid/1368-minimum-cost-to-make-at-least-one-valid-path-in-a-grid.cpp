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

 while(!dq.empty())

 {  

     auto temp = dq.front();

     int x =temp.second[0];

     int y =temp.second[1];

     int cost = temp.first;

     dq.pop_front();

     if(x==n-1 and y==m-1)return dist[x][y];

     //popping will always happer on the front side but pushing will be from both front and back

     for(int i=0;i<4;i++){

          int newCost = cost;

          if(dir[i]-'0' != c[x][y])

          {

              newCost++;

          }

          int newX = x+dx[i],newY = y+dy[i];

          if(newX >=0 and newY>=0 and newX <n and newY < m and newCost < dist[newX][newY])

          {

              if(newCost!=cost)

              {

                  dq.push_back({newCost,{newX,newY}});

              }

              else{

                  dq.push_front({newCost,{newX,newY}});

              }

              dist[newX][newY] = newCost;

          }

     }

 }

 return -1;
 
    }
};