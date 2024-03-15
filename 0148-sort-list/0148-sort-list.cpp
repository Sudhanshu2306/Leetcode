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

    ListNode* merge(ListNode* h1, ListNode* h2){
        ListNode* ans=new ListNode(-1);
        ListNode* temp=ans;
        while(h1!=nullptr && h2!=nullptr){
            if(h1->val<=h2->val) {
                temp->next=h1;
                h1=h1->next;
            }
            else{
                temp->next=h2;
                h2=h2->next;
            }
            temp=temp->next;
        }
        if(h1!=nullptr) temp->next=h1;
        if(h2!=nullptr) temp->next=h2;

        return ans->next;
    }

    ListNode* sortList(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return head;
        ListNode* slow=head, *fast=head->next;

        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* temp=slow->next;
        slow->next=nullptr;
        ListNode* h1=sortList(head);
        ListNode* h2=sortList(temp);

        return merge(h1,h2);
    }
};