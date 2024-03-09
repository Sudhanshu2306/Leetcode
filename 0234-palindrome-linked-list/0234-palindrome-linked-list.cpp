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

    ListNode* reverse(ListNode* head){
        ListNode* prev=nullptr;
        ListNode* curr=head;

        while(curr!=nullptr){
            ListNode* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return true;

        ListNode* slow=head;
        ListNode* fast=head;

        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* head2=reverse(slow);
        while(head2){
            if(head->val != head2->val) return false;
            head2=head2->next;
            head=head->next;
        }
        return true;
    }
};