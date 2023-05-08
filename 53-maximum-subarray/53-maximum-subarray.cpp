class Solution {
public:
    int maxSubArray(vector<int>& a) {
        int curr = a[0],mx = a[0];
        int n = a.size(); 
        
        for(int i=1;i<n;i++){
//             max sum ending at a particular index is either the no. itself or sum of it + curr
             curr = max(curr+a[i],a[i]);
             mx = max(mx,curr);
        }
        return mx;
    }
};