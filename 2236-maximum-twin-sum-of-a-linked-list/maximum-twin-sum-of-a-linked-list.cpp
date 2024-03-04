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
        ListNode* prev=NULL;
        ListNode* current=head;
        ListNode* next=NULL;

        while(current != NULL){
            next=current->next;
            current->next=prev;
            prev=current;
            current=next;
        }
        return prev;
    }

    int pairSum(ListNode* head) {
        int n=0;

        ListNode* temp=head;
        while(temp!=nullptr){
            n++;
            temp=temp->next;
        }
        temp=head;
        if(n==2) return temp->val+temp->next->val;

        int x=(n/2);
        
        while(x--){
            temp=temp->next;
        }

        temp=reverse(temp);

        int maxi=INT_MIN;
        while(temp!=nullptr){
            maxi=max(maxi,head->val+temp->val);
            head=head->next;
            temp=temp->next;
        }
        return maxi;
    }
};