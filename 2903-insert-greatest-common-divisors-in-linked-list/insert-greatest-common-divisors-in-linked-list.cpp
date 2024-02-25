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

    void f(ListNode* h1, ListNode*h2){
        if(h2==nullptr) return;

        int x=__gcd(h1->val,h2->val);
        ListNode* temp=new ListNode(x);

        temp->next=h2;
        h1->next=temp;

        f(h2,h2->next);
    }

    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head!=nullptr){
            if(head->next==nullptr) return head;
        }
        else return nullptr;

        ListNode* h1=head;
        ListNode* h2=head->next;

        f(h1,h2);
        return head;
    }
};