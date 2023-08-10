class Solution {
public:
    bool isBalanced(string s) {
    stack<char> st;
    for (auto i : s) {
        if (i == '(') {
            st.push(i);
        } else if (i == ')') {
            if (st.empty() || st.top() != '(') {
                return false;
            } else {
                st.pop();
            }
        }
    }
    return st.empty();
}
    void helper(string baseString, vector<string> &ans, int index, int n) {
        if (index == 2 * n) {
            if (isBalanced(baseString)) {
                ans.push_back(baseString);
            }
            return;
        }

        baseString.push_back('(');
        helper(baseString, ans, index + 1, n);
        baseString.pop_back();

        baseString.push_back(')');
        helper(baseString, ans, index + 1, n);
        baseString.pop_back();
    }
    vector<string> generateParenthesis(int n) {
//         generate all the combination and check each of them for if they are balanced or not
     vector<string> ans;
        string baseString = "";
        helper(baseString, ans, 0, n);
        return ans;
        
    }
};