/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        // Approach: Store elements in a stack and compare with the linked list elements
        stack<int> st;
        ListNode* p = head;
        ListNode* q = head;
        
        // Store elements in the stack
        while (p) {
            st.push(p->val);
            p = p->next;
        }
        
        // Compare linked list elements with stack elements
        while (!st.empty()) {
            if (q->val == st.top()) {
                q = q->next;
                st.pop();
            } else {
                return false;
            }
        }
        
        return true;
    }
};
