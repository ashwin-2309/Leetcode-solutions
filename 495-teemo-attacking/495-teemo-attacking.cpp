class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int n = timeSeries.size();
        if(n == 0)return 0;
        int res = 0;
        
        for(int i=0;i<n-1;i++){
            if(timeSeries[i+1] - timeSeries[i] < duration)
            {
                res+= timeSeries[i+1] - timeSeries[i];
            }
            else{
                res+=duration;
            }
        }
        return res+=duration;
    }
};