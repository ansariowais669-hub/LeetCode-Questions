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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2 ;
        else if(l2 == NULL) return l1 ;

        ListNode* temp1 = l1 ;
        ListNode* temp2 = l2 ;

        int carry = temp1->val + temp2->val ;
        ListNode* head = new ListNode(carry % 10) ;
        carry /= 10 ;
        ListNode* prev = head ;
        temp1 = temp1->next ; temp2 = temp2->next ;

        while(temp1 != NULL && temp2 != NULL){
            carry = temp1->val + temp2->val + carry ;
            ListNode* node = new ListNode(carry % 10) ;
            carry /= 10 ;

            temp1 = temp1->next ;
            temp2 = temp2->next ;

            prev->next = node ;
            prev = prev->next ;
        }

        while(temp1 != NULL){
            carry = temp1->val + carry ;
            ListNode* node = new ListNode(carry % 10) ;
            carry /= 10 ;
            temp1 = temp1->next ;

            prev->next = node ;
            prev = node ;
        }

        while(temp2 != NULL){
            carry = temp2->val + carry ;
            ListNode* node = new ListNode(carry % 10) ;
            carry /= 10 ;
            temp2 = temp2->next ;

            prev->next = node ;
            prev = node ;
        }

        if(carry != 0){
            ListNode* last = new ListNode(carry) ;
            prev->next = last ;
            prev = prev->next ;
        }

        prev->next = NULL ;

        return head ;
    }
};