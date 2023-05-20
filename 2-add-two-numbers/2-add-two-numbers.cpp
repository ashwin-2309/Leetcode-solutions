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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Create a dummy node and a temporary pointer
        auto dummy = new ListNode();
        auto temp = dummy;
        
        int carry = 0;
        
        // Iterate until both lists or the carry have elements
        while (l1 || l2 || carry) {
            int sum = 0;
            
            // Check if l1 has elements and add its value to the sum
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            
            // Check if l2 has elements and add its value to the sum
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            
            sum += carry; // Add the carry to the sum
            carry = sum / 10; // Calculate the new carry
            
            // Create a new node with the units digit of the sum
            auto node = new ListNode(sum % 10);
            
            // Connect the new node to the result list
            temp->next = node;
            temp = temp->next;
        }
        
        return dummy->next; // Return the result list starting from the next node of the dummy node
    }
};
