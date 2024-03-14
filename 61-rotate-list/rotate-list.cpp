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
    int len(ListNode* head){
        int n=0;
        ListNode* temp=head;
        while(temp){
            n++;
            temp=temp->next;
        }
        return n;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr || head->next==nullptr) return head;
        int n=len(head);

        if(k%n==0) return head;
        int x=k%n;

        ListNode* temp=head;
        ListNode* ans=nullptr;

        int t=n-x;
        while(temp->next!=nullptr){
            temp=temp->next;
        }
        temp->next=head;

        while(t--){
            ans=head;
            head=head->next;
        }
        ans->next=nullptr;
        return head;
    }
};