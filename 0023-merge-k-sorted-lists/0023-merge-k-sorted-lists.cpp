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
class Solution { // My solution --> O(nk^2)
public:
    ListNode* mergeKLists(vector<ListNode*>& lists){
        auto cmp = [](ListNode* a, ListNode* b) {return a->val > b->val ;} ;

        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq ;

        for(auto node : lists) if(node != NULL) pq.push(node) ;

        ListNode dummy(0) ;
        ListNode* temp = &dummy ;

        while(!pq.empty()){
            ListNode* node = pq.top() ;
            pq.pop() ;

            temp->next = node ;
            temp = temp->next ;

            if(node->next != NULL) pq.push(node->next) ;
        }

        temp->next = NULL ;
        return dummy.next ;
    }
};