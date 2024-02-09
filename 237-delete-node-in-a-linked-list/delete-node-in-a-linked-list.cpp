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
    void deleteNode(ListNode* node) {
        if(node->next==nullptr) node=nullptr;
        else{
            node->val=node->next->val;
            ListNode* temp=node->next->next;
            node->next->next=nullptr;
            node->next=temp;
        }
    }
};