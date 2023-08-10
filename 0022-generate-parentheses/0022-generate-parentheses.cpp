// class Solution {
// public:
//     bool isBalanced(string s) {
//     stack<char> st;
//     for (auto i : s) {
//         if (i == '(') {
//             st.push(i);
//         } else if (i == ')') {
//             if (st.empty() || st.top() != '(') {
//                 return false;
//             } else {
//                 st.pop();
//             }
//         }
//     }
//     return st.empty();
// }
//     void helper(string baseString, vector<string> &ans, int index, int n) {
//         if (index == 2 * n) {
//             if (isBalanced(baseString)) {
//                 ans.push_back(baseString);
//             }
//             return;
//         }

//         baseString.push_back('(');
//         helper(baseString, ans, index + 1, n);
//         baseString.pop_back();

//         baseString.push_back(')');
//         helper(baseString, ans, index + 1, n);
//         baseString.pop_back();
//     }
//     vector<string> generateParenthesis(int n) {
// //         generate all the combination and check each of them for if they are balanced or not
//      vector<string> ans;
//         string baseString = "";
//         helper(baseString, ans, 0, n);
//         return ans;
        
//     }
// };
class Solution {
public:
    void generateParenthesisHelper(vector<string> &result, string &current, int openCount, int closeCount, int n) {
        if (current.length() == 2 * n) {
            result.push_back(current);
            return;
        }
        
        if (openCount < n) {
            current.push_back('(');
            generateParenthesisHelper(result, current, openCount + 1, closeCount, n);
            current.pop_back();
        }
        
        if (closeCount < openCount) {
            current.push_back(')');
            generateParenthesisHelper(result, current, openCount, closeCount + 1, n);
            current.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current;
        generateParenthesisHelper(result, current, 0, 0, n);
        return result;
    }
};
