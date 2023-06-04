class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        if(a.size() > b.size())
        {
           return findMedianSortedArrays(b,a);
        }
        
//         a is the smaller array
    
        int x = a.size(),y = b.size();
        int totalSize = x+y;
//         element in one half = n+m/2
        int midSize = (x+y+1)/2;
        
//         now apply binary search
        int start = 0,end = x;
        int cut1,cut2;
        
        while(start <= end)
        {
           cut1 = (start + end)/2;
            cut2 = midSize - cut1;
            
            int lefta = (cut1>0)?a[cut1-1]:INT_MIN;
            int leftb = (cut2>0)?b[cut2-1]:INT_MIN;
            int righta = (cut1<x)?a[cut1]:INT_MAX;
            int rightb = (cut2<y)?b[cut2]:INT_MAX;
            
            if(lefta <= rightb and leftb <= righta)
            {
                if(totalSize%2 == 1)
                {
                    return max(lefta,leftb);
                }
                else{
                    return (max(lefta,leftb) + min(righta,rightb))/2.0;
                }
            }
            else if(lefta > rightb)
            {
                end = cut1-1;
            }
            else{
                start = cut1+1;
            }
        }
        return 0.0;
        
    }
};