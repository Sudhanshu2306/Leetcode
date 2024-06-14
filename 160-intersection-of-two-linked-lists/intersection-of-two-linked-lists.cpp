/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==nullptr || headB==nullptr) return nullptr;

        ListNode* ha=headA; ListNode* hb=headB;
        // int h1=0,h2=0;
        while(ha!=hb){
            ha=ha->next;
            hb=hb->next;
            
            if(ha==hb) return ha;

            if(ha==nullptr) ha=headB;
            if(hb==nullptr) hb=headA;

        }
        return ha;
    }
};