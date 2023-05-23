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
    Node* copyRandomList(Node* head) {
        return bruteForce(head);
    }
};