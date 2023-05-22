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
    ListNode* rotateRight(ListNode* head, int k) {
//         calculate length of the linked list and do k = k%length
        
//         now the last pointer will point to the head,and we need to make the length after k to be new head
        
        if(!head or !head->next or k==0)return head;
        
        auto curr = head;
        int len = 1;
        while(curr->next)
        {
            curr = curr->next;
            len++;
        }
        
        curr->next = head;
        k = k % len;
        k= len-k;
        
        while(k--)curr = curr->next;
        
        head = curr->next;
        curr->next = NULL;
        
        return head;
        
    }
};