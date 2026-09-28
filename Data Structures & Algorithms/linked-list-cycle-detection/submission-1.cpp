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
    bool hasCycle(ListNode* head) {
        if(head == nullptr || head->next == nullptr || head->next->next == nullptr) return false;
        ListNode* fp = head->next->next;
        ListNode* sp = head->next;
        while(fp != sp){
            if(fp == nullptr || fp->next == nullptr || fp->next->next == nullptr) return false;
            fp = fp->next->next;
            sp = sp->next;
        }
        return true;
    }
};
