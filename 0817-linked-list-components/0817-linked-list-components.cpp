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
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set <int> s ;
        for(int dig : nums) s.insert(dig) ;

        ListNode* temp = head ;
        ListNode* tempNext = temp->next ;

        int connected ;
        if(s.find(temp->val) != s.end()) connected = 1 ;
        else connected = 0 ;

        while(tempNext != NULL){
            if(s.find(temp->val) == s.end() && s.find(tempNext->val) != s.end()) connected++ ;
            temp = temp->next ;
            tempNext = tempNext->next ;
        }
        return connected ;
    }
};
