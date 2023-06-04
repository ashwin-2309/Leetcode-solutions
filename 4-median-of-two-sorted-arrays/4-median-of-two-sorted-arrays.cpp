class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        if(a.size() > b.size())
        {
         return   findMedianSortedArrays(b,a); // Swap the arrays if 'a' is larger than 'b'
        }
        
        // 'a' is the smaller array
        int x = a.size(),y = b.size();
        int totalSize = x+y; // Total number of elements in both arrays
        int midSize = (x+y+1)/2; // Size of the first half when merged
        
        // Now apply binary search
        int start = 0,end = x;
        int cut1,cut2;
        
        while(start <= end)
        {
           cut1 = (start + end)/2; // Cut point in 'a'
            cut2 = midSize - cut1; // Cut point in 'b'
            
            // Find the elements on the left and right side of the cut points
            int lefta = (cut1>0)?a[cut1-1]:INT_MIN; // Left element in 'a'
            int leftb = (cut2>0)?b[cut2-1]:INT_MIN; // Left element in 'b'
            int righta = (cut1<x)?a[cut1]:INT_MAX; // Right element in 'a'
            int rightb = (cut2<y)?b[cut2]:INT_MAX; // Right element in 'b'
            
            if(lefta <= rightb and leftb <= righta)
            {
                // Found the correct cut points, calculate the median
                if(totalSize%2 == 1)
                {
                    return max(lefta,leftb); // Median for odd total size
                }
                else{
                    return (max(lefta,leftb) + min(righta,rightb))/2.0; // Median for even total size
                }
            }
            else if(lefta > rightb)
            {
                end = cut1-1; // Adjust the end point for binary search
            }
            else{
                start = cut1+1; // Adjust the start point for binary search
            }
        }
        return 0.0; // Default return value if no median is found
        
    }
};
