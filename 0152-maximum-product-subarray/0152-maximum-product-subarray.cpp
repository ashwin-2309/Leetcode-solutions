class Solution {
public:
    int maxProduct(vector<int>& a) {
      int mina=a[0],maxa=a[0];
    int ans = maxa;
        for(int i=1;i<a.size();i++){
            if(a[i]<0){
                swap(mina,maxa);
            }
            maxa=max(a[i],maxa*a[i]);
            mina=min(a[i],mina*a[i]);
            ans = max(ans,maxa);
        }
        return ans;
    }
};