class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
         vector<vector<int>> res;
         int i=0,j=0;
        int x =firstList.size(),y=secondList.size();
        
        while(i<x and j < y)
        {
            auto a = firstList[i][0],b=firstList[i][1],c=secondList[j][0],d=secondList[j][1];
            int newX = max(a,c);
            int newY = min(b,d);
            if(newY>=newX)
                res.push_back({newX,newY});
            
            if(b > d)j++;
            else i++;
        }
        return res;
    }
};