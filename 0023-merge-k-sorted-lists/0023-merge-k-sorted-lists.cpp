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
    ListNode* merge(ListNode* left , ListNode* right){
        ListNode dummy(0) ;
        ListNode* temp = &dummy ;

        while(left != NULL && right != NULL){
            if(left->val <= right->val){
                temp->next = left ;
                left = left->next ;
            }else{
                temp->next = right ;
                right = right->next ;
            }

            temp = temp->next ;
        }

        while(left != NULL){
            temp->next = left ;
            left = left->next ;

            temp = temp->next ;
        }

        while(right != NULL){
            temp->next = right ;
            right = right->next ;

            temp = temp->next ;
        }

        return dummy.next ;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL ;
        else if(lists.size() == 1) return lists[0] ;

        ListNode* head = lists[0] ;

        for(int i=1 ; i<lists.size() ; i++){
            if(lists[i] == NULL) continue ;

            head = merge(head, lists[i]) ;
        }

        return head ;
    }
};