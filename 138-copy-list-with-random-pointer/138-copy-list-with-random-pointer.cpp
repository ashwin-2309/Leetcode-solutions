/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    
    Node* bruteForce(Node* head)
    {
        unordered_map<Node*,Node*> m;
        auto temp = head;
        
        while(temp != NULL){
//             create a new node with same val
            Node* x = new Node(temp->val);
            m.insert({make_pair(temp,x)});
            temp=temp->next;
        }
        
//         now we have the mapping now we populate the next and random pointers
        auto newTemp = head;
        while(newTemp != NULL){
            auto y = m[newTemp];
            y->next = m[newTemp->next];
            y->random = m[newTemp->random];
            newTemp = newTemp->next;
        }
        auto newHead = m[head];
        return newHead;
    }
    
    Node* optimal(Node* head)
    {
//         we will do it without any mapping or extra space
        auto iter = head;
        auto front = head;
        
//         insert copy between the original nodes
        
        while(iter != NULL)
        {
            front = iter->next;
            auto copy = new Node(iter->val);
            iter->next = copy;
            copy->next = front;
            iter = front;
        }
        
// populate random pointers in the copy nodes
        iter = head;
        while (iter != NULL) {
            if (iter->random != NULL) {
              iter->next->random = iter->random->next;
            }
            iter = iter->next->next;
          }
//         now get the copy linked list out of there
          iter = head;
        
          Node *pseudoHead = new Node(0);
          Node *copy = pseudoHead;

          while (iter != NULL) {
//           Node which is in original linked list
            front = iter->next->next;

            // extract the copy
            copy->next = iter->next;

            // restore the original list
            iter->next = front;
              
            copy = copy -> next; 
            iter = front;
          }
        return pseudoHead->next;
        
    }
    
    Node* copyRandomList(Node* head) {
        // return bruteForce(head);
        return optimal(head);
    }
};