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
    // intution: reverse the second half of the list, this will be needed for adding nodes in order
    ListNode* revList(ListNode* head){
        ListNode* prev=nullptr;
        ListNode* curr=head;
        ListNode* next;

        while(curr!=nullptr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        ListNode* slow=head; ListNode* fast=head;

        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode* h2=revList(slow->next);
        ListNode* h1=head;
        slow->next=nullptr;
        while(h2!=nullptr){
            ListNode* temp=h1->next;
            h1->next=h2;
            h1=h2;
            h2=temp;
        }
    }
};