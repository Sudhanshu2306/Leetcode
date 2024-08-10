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
    // ListNode* reverse(ListNode* head){
    //     ListNode* temp=head;
    //     ListNode* prev=nullptr;
    //     ListNode* next=nullptr;
    //     while(temp!=nullptr){
    //         next=temp->next;
    //         temp->next=prev;
    //         prev=temp; temp=next;
    //     }
    //     return prev;
    // }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy=new ListNode(-1);
        ListNode* curr=dummy;
        // ListNode* h1=reverse(l1);
        // ListNode* h2=reverse(l2);
        int carry=0;
        while(l1!=nullptr || l2!=nullptr || carry!=0){
            int sum=0;
            if(l1!=nullptr) {
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2!=nullptr) {
                sum+=l2->val;
                l2=l2->next;
            }
            sum+=carry;
            carry=(sum)/10;
            curr->next=new ListNode(sum%10);
            curr=curr->next;
        }
        return dummy->next;
    }
};