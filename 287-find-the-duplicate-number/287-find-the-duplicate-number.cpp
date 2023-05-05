class Solution {
public:
    int tortoiseHare(vector<int> &a)
    {
        int slow = a[0],fast = a[a[0]];
        while(slow != fast)
        {
            slow = a[slow];
            fast = a[a[fast]];
        }
//         slow = fast
        fast = 0;
        while(slow != fast)
        {
            slow = a[slow];
            fast = a[fast];
        }
        return fast;
    }
    int findDuplicate(vector<int>& nums) {
//         tortoise hare algo
        return tortoiseHare(nums);
    }
};