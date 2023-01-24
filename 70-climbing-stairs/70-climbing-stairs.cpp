class Solution {
public:
    int climbStairs(int n) {
        if(n<=2)return n;
     int prev2=1;
     int prev=2;
    int curr;
     for(int i=2;i<n;i++)
     {
         curr=prev2+prev;
         prev2=prev;
         prev=curr;
     }
     return curr;
    }
};