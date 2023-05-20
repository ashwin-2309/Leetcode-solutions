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
    void reorderList(ListNode* head) {
        // Edge cases: if there are no nodes or only one or two nodes, no reordering is required
        if (!head || !head->next || !head->next->next) {
            return;
        }
        
        // Use a stack to store the nodes
        stack<ListNode*> nodeStack;
        ListNode* ptr = head;
        int size = 0;
        
        // Put all nodes in the stack and count the number of nodes
        while (ptr != NULL) {
            nodeStack.push(ptr);
            size++;
            ptr = ptr->next;
        }
        
        ListNode* pptr = head;
        // Reorder the list by inserting nodes between every two nodes
        for (int j = 0; j < size / 2; j++) {
            ListNode* element = nodeStack.top();
            nodeStack.pop();
            element->next = pptr->next;
            pptr->next = element;
            pptr = pptr->next->next;
        }
        
        // Set the next pointer of the last node to NULL
        pptr->next = NULL;
    }
};
