class Solution {
public:
    void prevPermutation(vector<int> &a)
    {
        
    }
    void nextPermutation(vector<int>& a) {
//         find the last point where a[i+1] > a[i]
//         if there isn't then reverse the vector and return it
//         else travel from the back and find a no. which is bigger than the current no.(first) and swap
//         and reverse the swapped index+1,end part
        
        int n = a.size(); 
        int index = -1;
        for(int i=0;i<n-1;i++)
        {
            if(a[i+1] > a[i])index = i;
        }
        
        if(index == -1)
        {
//             reverse the vector
            reverse(a.begin(),a.end());
            return;
        }
        
//         now find the no. which is greater than this no. from the back
        for(int i=n-1;i>index;i--){
            if(a[i] > a[index])
            {
                swap(a[i],a[index]);
                break;
            }
        }
//         reverse the no.s left
        
        reverse(a.begin()+index+1,a.end());
    }
};