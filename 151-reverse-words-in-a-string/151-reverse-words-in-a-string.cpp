class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        
        int i = 0, j = 0, n = s.size(), lastIndex = 0;
        
        while(j < n){
            // Find the starting index of the word: Skipping empty spaces before the word.
            while(j < n && s[j] == ' ') j++;
            
            int startIndex = i;
            
            // Store the complete word... : 
            while(j < n && s[j] != ' '){
                s[i++] = s[j++];
                lastIndex = i;
            }
            
            // Reverse the word
            reverse(s.begin() + startIndex, s.begin() + lastIndex);
            s[i++] = ' '; // after every word we need space [" "]
        }
        
        // Resize the string to the last index of the last word: to avoid empty spaces at the end.
        s.resize(lastIndex);
        return s;
    }
};