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
    int GCD(int a, int b){
        while(b != 0){
            int temp = b ;
            b = a % b ;
            a = temp ;
        }
        return a ;
    }

    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* temp = head ;
        ListNode* forward = temp->next ;

        while(forward != NULL){
            int val = GCD(temp->val, forward->val) ;
            ListNode* ptr = new ListNode(val) ;

            temp->next = ptr ;
            ptr->next = forward ;

            temp = forward ; 
            forward = forward->next ;
        }
        return head ;
    }
};