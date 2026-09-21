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
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) return head;
        ListNode* node = head;
        ListNode* prevNode = nullptr;
        while (node->next != nullptr){
            ListNode* nxtNode = node->next;
            node->next = prevNode;
            prevNode = node;
            node = nxtNode;
        }
        node->next = prevNode;
        return node;
    }
};
