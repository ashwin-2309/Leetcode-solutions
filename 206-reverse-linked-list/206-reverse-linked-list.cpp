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
    ListNode* iterativeReverse(ListNode* head)
    {
        ListNode *prev=NULL,*curr=NULL,*fwd = head;
        while(fwd)
        {
            curr = fwd;
            fwd = fwd->next;
            
            curr->next = prev;
            prev = curr;
        }
      head = curr;
      return head;
    }
    
    ListNode* recursiveReverse(ListNode* head)
    {
        if(head == NULL or head->next == NULL)
        {
            return head;
        }
        
        ListNode* rest = recursiveReverse(head->next);
        head->next->next = head;
        
        head->next = NULL;
        return rest;
        
    }
    
    ListNode* reverseList(ListNode* head) {
        return iterativeReverse(head);
    }
};