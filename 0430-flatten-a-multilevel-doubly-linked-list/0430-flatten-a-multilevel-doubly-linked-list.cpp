/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/



class Solution {
public:
    Node* flatten(Node* head) {
        if(head == NULL) return NULL ;

        Node* temp = head ;

        while(temp != NULL){
            if(temp->child){
                Node* nextptr = temp->next ;
                temp->next = flatten(temp->child) ;
                temp->next->prev = temp ;
                temp->child = NULL ;

                while(temp->next != NULL) temp = temp->next ;

                if(nextptr != NULL){
                    temp->next = nextptr ;
                    nextptr->prev = temp ;
                }
            }
            temp = temp->next ;
        }

        return head ;
    }
};