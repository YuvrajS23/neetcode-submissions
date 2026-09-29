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
    ListNode* addANumber(int i, ListNode* l){
        ListNode* cur = l;
        while(cur != nullptr){
            if(cur->val + i < 10){
                cur->val += i;
                i = 0;
            }
            else{
                cur->val = (cur->val + i) % 10;
                i = 1;
            }
            if(cur->next == nullptr && i > 0){
                ListNode* next = new ListNode(i);
                cur->next = next;
                cur = cur->next;
            }
            cur = cur->next;
        }
        return l;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* cur1 = l1;
        ListNode* cur2 = l2;
        while(cur1 != nullptr && cur2 != nullptr){
            int sum = cur1->val + cur2->val + carry;
            if(sum < 10){
                cur1->val = sum;
                carry = 0;
            }
            else{
                cur1->val = sum % 10;
                carry = 1;
            }
            if(cur1->next == nullptr){
                if(cur2->next == nullptr){
                    if(carry > 0){
                        ListNode* next = new ListNode(carry);
                        cur1->next = next;
                        cur1 = cur1->next;
                        return l1;
                    }
                }
                else{
                    cur1->next = cur2->next;
                    cur2->next = addANumber(carry, cur2->next);
                    return l1;
                }
            }
            if(cur2->next == nullptr){
                if(cur1->next != nullptr){
                    cur1->next = addANumber(carry, cur1->next);
                    return l1;
                }
            }
            cur1 = cur1->next;
            cur2 = cur2->next;

        }

        if(cur1 == nullptr){
            if(cur2 == nullptr){
                if(carry > 0){
                    ListNode* next = new ListNode(carry);
                    return next;
                }
            }
            else{
                cur2 = addANumber(carry, cur2);
                return cur2;
            }
        }
        if(cur2 == nullptr){
            if(cur1 != nullptr){
                cur1 = addANumber(carry, cur1);
                return l1;
            }
        }
        return l1;
    }
};
