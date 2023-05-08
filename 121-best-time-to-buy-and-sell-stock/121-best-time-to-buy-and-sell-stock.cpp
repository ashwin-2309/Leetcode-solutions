class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0],maxProfit = INT_MIN;
        for(auto &i : prices){
             minPrice = min(minPrice,i);
             maxProfit = max(maxProfit,i-minPrice);
        }
        return maxProfit;
    }
};