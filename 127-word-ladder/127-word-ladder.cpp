class Solution {
public:
    int ladderLength(string start, string target, vector<string>& a) {
        unordered_set<string> s(a.begin(), a.end());
        queue<string> q;
        q.push(start);
        int level = 1;
        while (!q.empty()) {
            int size = q.size();
            
            // Iterate through all the words in the current level of the BFS tree
            for (int i = 0; i < size; i++) {
                // Get the current word from the front of the queue
                string word = q.front();
                q.pop();
                
                // If the current word is the target word, return the level
                if (word == target) {
                    return level;
                }
                
                // Iterate through each character in the current word
                for (int j = 0; j < word.size(); j++) {
                    // Save the original character at the current position
                    char original = word[j];
                    
                    // Try replacing the character at the current position with all the lowercase letters
                    for (char ch = 'a'; ch <= 'z'; ch++) {
                        word[j] = ch;
                        
                        // If the modified word is in the set of words, add it to the queue and remove it from the set
                        if (s.count(word)) {
                            q.push(word);
                            s.erase(word);
                        }
                    }
                    // Restore the original character in the current position
                    word[j] = original;
                }
            }
            // Increment the level after processing all the words in the current level
            level++;
        }
        
        // If the queue becomes empty and the target word is not found, return 0
        return 0;
    }
};