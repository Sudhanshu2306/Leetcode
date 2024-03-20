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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* h1=list1;
        a-=1;
        while(a--){
            h1=h1->next;
        }
        ListNode* h2=list1;
        while(b--){
            h2=h2->next;
        }
        h2=h2->next;

        ListNode* h3=list2;
        while(h3->next!=nullptr) h3=h3->next;

        h1->next=list2; 
        h3->next=h2;

        return list1;
    }
};