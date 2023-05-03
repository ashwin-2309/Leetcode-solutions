class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        int maxProfit = 0;
        
        for(auto &i : prices){
             minPrice = min(i,minPrice);
             maxProfit = max(maxProfit,i-minPrice);
        }
        
        return maxProfit;
    }
};