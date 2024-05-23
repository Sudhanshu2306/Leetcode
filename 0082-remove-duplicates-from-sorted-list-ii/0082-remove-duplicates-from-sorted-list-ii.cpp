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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return head; 
        ListNode *i=nullptr;
        ListNode *j=head;
        while(j!=nullptr){
            int x=j->val;
            int f=0;
            ListNode* prev=i;
            while(j && j->val==x){
                f++;
                i=j;
                j=j->next;
            }
            if(f>1){
                i=prev;
                if(prev==nullptr) head=j;
                else prev->next=j;
            }
        }
        return head;
    }
};