// This class provides a solution for trapping rainwater.

class Solution {
public:
    // Helper function to calculate the optimal amount of trapped rainwater
    int optimal(vector<int> &height)
    {
        int n = height.size();
        
        // If the array size is less than or equal to 2, no water can be trapped
        if (n <= 2)
            return 0;
        
        int left = 0;
        int right = n - 1;
        int res = 0;
        int maxleft = 0;
        int maxright = 0;
        
        while (left <= right) {
            if (height[left] <= height[right]) {
                // The current left wall is smaller or equal to the current right wall
                // We can determine if water can be trapped at the current left position
                
                if (height[left] >= maxleft) {
                    // The current left wall is higher than or equal to the highest left wall encountered so far
                    // Update the highest left wall
                    maxleft = height[left];
                } else {
                    // The current left wall is lower than the highest left wall encountered so far
                    // Water can be trapped at the current position
                    // Calculate the amount of water that can be trapped by subtracting the current left wall height from the highest left wall height
                    res += maxleft - height[left];
                }
                
                // Move the left pointer to the right
                left++;
            }
            else {
                // The current right wall is smaller than the current left wall
                // We can determine if water can be trapped at the current right position
                
                if (height[right] >= maxright) {
                    // The current right wall is higher than or equal to the highest right wall encountered so far
                    // Update the highest right wall
                    maxright = height[right];
                } else {
                    // The current right wall is lower than the highest right wall encountered so far
                    // Water can be trapped at the current position
                    // Calculate the amount of water that can be trapped by subtracting the current right wall height from the highest right wall height
                    res += maxright - height[right];
                }
                
                // Move the right pointer to the left
                right--;
            }
        }
        
        return res;
    }
    
    // Function to trap rainwater
    int trap(vector<int>& height) {
        return optimal(height);
    }
};
