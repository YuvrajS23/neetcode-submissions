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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode* dummy = head;
        while(dummy != nullptr){
            len++;
            dummy = dummy->next;
        }

        ListNode* prev = nullptr;
        ListNode* curr = head;
        len = len - n;
        if(len == 0) return head->next;
        while(len != 0){
            prev = curr;
            curr = curr->next;
            len--;
        }
        prev->next = curr->next;
        return head;
    }
};
