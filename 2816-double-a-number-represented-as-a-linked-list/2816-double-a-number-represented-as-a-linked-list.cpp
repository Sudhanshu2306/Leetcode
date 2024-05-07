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
    ListNode* reverse(ListNode* head){

        ListNode* prev=nullptr;
        ListNode* curr=head;
        ListNode* forward;

        while(curr){
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        return prev;
    }
public:
    ListNode* doubleIt(ListNode* head) {
        head=reverse(head);

        ListNode* curr=head;
        ListNode* prev=head;

        int c=0;
        while(true){
            if(curr==nullptr){
                if(c>0){
                    prev->next=new ListNode(c);
                }
                break;
            }
            int x=curr->val;
            int y=x*2;
            y+=c;
            int value=y%10;
            c=y/10;
            curr->val=value;
            prev=curr;
            curr=curr->next;
        }
        return reverse(head);
    }
};