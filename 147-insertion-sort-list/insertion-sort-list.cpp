class Solution {
public:

    ListNode* merge(ListNode* left ,ListNode* right){

        ListNode dummy(0) ;
        ListNode* tail = &dummy ;

        while(left != NULL && right != NULL){
            if(left->val < right->val) {
                tail->next = left ;
                left = left->next ;
            } else if(right->val <= left->val){
                tail->next = right ;
                right = right->next ;
            }
            tail = tail->next ;
        }

        if(left != NULL){
            tail->next = left ;
        }

        if(right != NULL){
            tail->next = right ;
        }

        return dummy.next ;
    }


    ListNode* insertionSortList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head ;

        ListNode* slow = head ;
        ListNode* fast = head->next ;

        while(fast != NULL 
            && fast->next != NULL){
            slow = slow->next ;
            fast = fast->next->next ;
        }

        ListNode* right = slow->next ;
        ListNode* left = head ;
        slow->next = NULL ;

        left = insertionSortList(left) ;
        right = insertionSortList(right) ;

        return merge(left, right) ;
    }
};
