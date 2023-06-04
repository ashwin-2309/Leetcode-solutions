class Solution {
public:
    int singleNonDuplicate(vector<int>& a) {
//         apply general purpose binary search but just check if the mid has an element
        int start = 0,end = a.size()-1;
//         -2 is important
        while(start < end)
        {
            int mid = start+(end-start)/2;
            if(a[mid] == a[mid^1])
            {
                start = mid+1;   
            }
            else{
                end = mid;
            }
        }
        return a[start];
    }
};