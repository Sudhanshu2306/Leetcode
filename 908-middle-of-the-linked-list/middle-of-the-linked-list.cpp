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
    ListNode* middleNode(ListNode* head) {
        // if(head==nullptr || head->next==nullptr) return head;

        ListNode* p=head;
        ListNode* q=head;

        p = q = head;

        while(q->next){
            p = p->next;
            if(q->next->next) q = q->next->next;
            else q = q->next;
        }
        return p;
    }
};