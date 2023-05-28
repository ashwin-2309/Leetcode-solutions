class Solution {
public:
    // Check if a substring is a palindrome
    bool isPalindrome(string s, int start, int end) {
        while (start <= end) {
            if (s[start++] != s[end--]) {
                return false;
            }
        }
        return true; 
    }
    
    // Helper function for backtracking
    void helper(int index, string s, vector<string>& path, vector<vector<string>>& res) {
        if (index == s.length()) {
            // Reached the end of the string, add the current partition to the result
            res.push_back(path);
            return;
        }
        for (int i = index; i < s.size(); i++) {
            if (isPalindrome(s, index, i)) {
                // If the current substring is a palindrome, add it to the path
                path.push_back(s.substr(index, i - index + 1));
                
                // Recursive call to find palindromic partitions for the remaining substring
                helper(i + 1, s, path, res);
                
                // Remove the last added substring from the path to backtrack
                path.pop_back();
            }
        }
    }
    
    // Main function to find all palindromic partitions of a string
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        helper(0, s, path, res);
        return res;
    }
};
