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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL) return head ;
        ListNode* prev = NULL ;
        ListNode* first = head ;
        ListNode* second = first->next ;
        while(second != NULL && first != NULL){
            first->next = second->next ;
            if(prev != NULL) prev->next = second ;
            second->next = first ;
            if(first == head) head = second ;

            prev = first ;
            if(prev != NULL) first = prev->next ;
            if(first != NULL) second = first->next ;
        }
        return head ;
    }
};