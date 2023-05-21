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
   ListNode* findMiddle(ListNode* head) {
    ListNode* slowPtr = head;
    ListNode* fastPtr = head;

    while (fastPtr != nullptr && fastPtr->next != nullptr) {
        fastPtr = fastPtr->next->next;
        slowPtr = slowPtr->next;
    }

    return slowPtr;
}

ListNode* reverseList(ListNode* head) {
    ListNode* current = head;
    ListNode* previous = nullptr;
    ListNode* next = nullptr;

    while (current != nullptr) {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }

    return previous;
}

int pairSum(ListNode* head) {
    int maxPairSum = 0;

    ListNode* middleNode = findMiddle(head);
    ListNode* reversedHalf = reverseList(middleNode);

    ListNode* current = head;
    while (reversedHalf != nullptr) {
        maxPairSum = max(maxPairSum, reversedHalf->val + current->val);
        reversedHalf = reversedHalf->next;
        current = current->next;
    }

    return maxPairSum;
}

};