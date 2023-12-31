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
    ListNode* removeNodes(ListNode* head) {
        if(head==nullptr)
            return head;
        
        stack<ListNode*> st;
        ListNode* curr=head;
        while(curr!=nullptr){
            while(!st.empty() && curr->val > st.top()->val){
                st.pop();
            }
            st.push(curr);
            curr=curr->next;
        }
        
        ListNode* newHead = nullptr;
        ListNode* temp = nullptr; 

        while (!st.empty()) {
            ListNode* temp = st.top();
            st.pop();
            temp->next = newHead;
            newHead = temp;
        }
        

        return newHead;
    }
};