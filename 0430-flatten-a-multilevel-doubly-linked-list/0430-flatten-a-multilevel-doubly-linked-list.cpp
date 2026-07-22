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
        if(head == NULL) return head ;

        Node* curr = head ;
        while (curr != NULL)
        {
            if(curr->child != NULL){
                // Flatten the child Nodes
                Node* Next = curr->next ;
                curr->next = flatten(curr->child) ;

                curr->next->prev = curr ;
                curr->child = NULL ;

                // Find tail
                while(curr->next != NULL) curr = curr->next ;

                // Attach tail with the next pointer
                if(Next != NULL){
                    curr->next = Next ;
                    Next->prev = curr ;
                }
            }
            curr = curr->next ;
        }
        return head ;
    }
};