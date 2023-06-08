class Solution {
public:
    int maxHeap(vector<int> &nums,int k)
    {
        priority_queue<int> maxHeap;
//         max element at top
        for(auto &i : nums)maxHeap.push(i);
        
        for(int i=0;i<k-1;i++){
             maxHeap.pop();
        }
        return maxHeap.top();
    }
    
    int minHeap(vector<int> &nums,int k)
    {
        //      here we have kth largest so we use minHeap
//         minHeap(min element at top)
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
    int findKthLargest(vector<int>& nums, int k) {
        return maxHeap(nums,k);
    }
};