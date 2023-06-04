class Solution {
public:
    int search(vector<int>& a, int target) {
//         find the pivot point
        int start = 0,end = a.size()-1;
        while(start <= end)
        {
            int mid = start + (end-start)/2;
            int element = a[mid];
            if(a[mid] == target)return mid;
//             check if left half is sorted
            if(a[mid] >= a[start])
            {
                if(target <= a[mid] and target >= a[start])
                {
                    end  = mid-1;
                }
//                 target is on the right side
                else{
                    start = mid+1;
                }
            }
            else{
//                 right side is sorted so check if the element is on the right side
                if(target >= a[mid] and target <= a[end])
                {
                    start = mid+1;
                }
                else{
                    end = mid-1;
                }
            }
        }
        return -1;
    }
};