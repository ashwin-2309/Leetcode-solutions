class Solution {
public:
    int lengthOfLongestSubstring(string s) {
     // return longest substring without repeating characters
        // sliding window
        int n = s.length();
        int i = 0, j = 0, ans = 0;
        unordered_map<char, int> m;
        while (j < n)
        {
            if (m.find(s[j]) != m.end())
            {
                i = max(i, m[s[j]] + 1);
            }
            m[s[j]] = j;
            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;   
    }
};