class Solution {
public:
    void sortColors(vector<int>& a) {
//         we will have low,mid,high
//         now all no.s before low will be 0 and all no.s above high will be 2 and no.s between low and high will be 1
        int n = a.size(); 
        int low = 0,mid = 0,high = n-1;
        
        while(mid <= high)
        {
            if(a[mid] == 0)
            {
                swap(a[low],a[mid]);
                low++,mid++;
            }
            else if(a[mid] == 1)
            {
                mid++;
            }
            else{
                swap(a[mid],a[high]);
                high--;
            }
        }
        return;
    }
};