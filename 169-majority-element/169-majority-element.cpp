class Solution {
public:
    
    int majorityElementBrute(vector<int> &a)
    {
        int mxCount = 0;
        int currCount = 0;
        
//         2 for loops,check occurrence of this element 
        int n = a.size(); 
        
        for(int i=0;i<n;i++){
            int currElement = a[i];
               for(int j=0;j<n;j++){
                   if(i != j and a[j] == a[i])
                   {
                        currCount++;
                   }
               }
            mxCount = max(mxCount,currCount+1);
            if(mxCount > n/2)return currElement;
        }
        return -1;
        
    }
    
    int majorityElementBetter(vector<int> &a)
    {
        int count = 0;
        int candidate;
        for(auto num : a)
        {
            if(count == 0)
            {
                candidate = num;
            }
            
            count+=(num == candidate) ? 1 : -1;
        }
        
        return candidate;
        
    }
    
    int majorityElement(vector<int>& nums) {
        // return majorityElementBrute(nums);
        
        return majorityElementBetter(nums);
    }
};