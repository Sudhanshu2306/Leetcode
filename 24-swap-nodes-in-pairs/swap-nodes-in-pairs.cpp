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
    ListNode* swapPairs(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return head;


        ListNode* ans=new ListNode();
        ListNode* prev=ans;
        ListNode* curr=head;
  
        while(curr && curr->next){
            prev->next=curr->next;
            curr->next=prev->next->next;
            prev->next->next=curr;

            prev=curr;
            curr=curr->next;
        }
        return ans->next;
    }
};