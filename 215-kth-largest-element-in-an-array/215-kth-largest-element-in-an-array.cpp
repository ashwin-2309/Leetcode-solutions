class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
//      here we have kth largest so we use minHeap
        priority_queue<int,vector<int>,greater<int>> minHeap;
        
        for(auto &i : nums)
        {
            minHeap.push(i);
            
            if(minHeap.size() > k)
            {
                minHeap.pop();
            }
        }
    return minHeap.top();
    }
};