class Solution {
public:
    
    int findDuplicate(vector<int>& a) {
//         we need to return the element which is repeated
        int fast = a[a[0]],slow = a[0];
        while(fast != slow)
        {
            fast = a[a[fast]],slow = a[slow];
        }
        
//         now they are same
        fast = 0;
        while(fast != slow)
        {
            fast = a[fast],slow = a[slow];
        }
        return slow;
    }
};