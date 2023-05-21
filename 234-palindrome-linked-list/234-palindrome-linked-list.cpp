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
    
    ListNode* middleOfList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast != nullptr && fast->next != nullptr and fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
    
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        
        while (curr != nullptr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return true;
        
        ListNode* middleNode = middleOfList(head);
        ListNode* rightHead = reverseList(middleNode->next);
        middleNode->next = rightHead;
        
        ListNode* leftPtr = head;
        ListNode* rightPtr = rightHead;
        
        while (rightPtr != nullptr) {
            if (leftPtr->val != rightPtr->val)
                return false;
            
            leftPtr = leftPtr->next;
            rightPtr = rightPtr->next;
        }
        
        return true;
    }
};
