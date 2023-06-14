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
typedef pair<int,ListNode*> pil;
class Solution {
public:
    ListNode* heapSolution(vector<ListNode*> &lists)
    {
        ListNode* dummy = new ListNode();
        ListNode* temp = dummy;
        
        priority_queue<pil,vector<pil>,greater<pil>> pq;
        
        for(auto &i : lists)
        {
            if(i)
            {
                pq.push({i->val,i});
            }
        }
        
        while(!pq.empty())
        {
            auto top  = pq.top();
            pq.pop();
            
            auto ptr = top.second;
            
            temp->next = ptr;
            temp = temp->next;
            
            if(ptr->next)
            {
                pq.push({ptr->next->val,ptr->next});
            }
        }
        return dummy->next;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return heapSolution(lists);
    }
};