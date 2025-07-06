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
    // Node* f(Node* head, Node* next){
    //     if(head==nullptr) return next;

    //     head->next=f(head->child,f(head->next,next));
    //     if(head->next) head->next->prev=head;
    //     head->child=nullptr;

    //     return head;
    // }
    Node* flatten(Node* head) {
        // return f(head,nullptr);
        if(head==nullptr) return head;

        Node* tail=head;
        Node* next=flatten(head->child);
        Node* next_next=flatten(head->next);

        if(next!=nullptr){
            tail->next=next;
            while(tail->next!=nullptr){
                tail->next->prev=tail;
                tail->child=nullptr;
                tail=tail->next;
            }
        }
        tail->next=next_next;
        if(next_next!=nullptr) next_next->prev=tail;
        return head;
    }
};