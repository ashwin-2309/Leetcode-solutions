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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL)return l2;
        if(l2 == NULL)return l1;
        
//         l1 will be always be the smaller one
        
        if(l1->val > l2->val)swap(l1,l2);
        
        ListNode *res = l1;
        
        while(l1 and l2){
            
            ListNode* temp = NULL;
            
//             just move further in the l1 list no need of using the data from other list
            while(l1 != NULL and l1->val <= l2->val){
                temp = l1;
                l1 = l1->next;
            }
//             here we need to change the list ie incorporate element from the other list so we use our temp Node to go to l2
//             now l1 was temp->next earlier so it is easier to incorporate l1 as well
//             now we swap as l1 < l2(val wise)
            
            temp->next = l2;
            swap(l1,l2);
        }
        return res;
    }
};