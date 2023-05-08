#define ll long long
class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        vector<ll> ans;
        if(num % 3 != 0)return ans;
        
        ll b = num/3;
        ll a = b-1;
        ll c = b+1;
        
        return {a,b,c};
    }
};