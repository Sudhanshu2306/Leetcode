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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length=0;
        ListNode* temp=head;
        ListNode* prev;
        while(temp!=nullptr){
            length++;
            prev=temp;
            temp=temp->next;
        }
        int ns=length-n-1;
        if(n==1 && length==1) return nullptr;

        if(ns==-1) return head->next;
        temp=head;
        while(ns--){
            temp=temp->next;
        }
        ListNode* next=temp->next;
        temp->next=temp->next->next;
        next->next =nullptr;
        return head;
    }
};