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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> st(nums.begin(),nums.end());

        ListNode* temp=head;
        while(st.find(temp->val)!=st.end()){
            temp=temp->next;
        }
        head=temp;
        while(temp->next!=nullptr){
            if(st.find(temp->next->val)!=st.end()){
                ListNode* n=temp->next;
                temp->next=n->next;
                n->next=nullptr;
            }
            else{
                temp=temp->next;
            }
        }
        return head;
    }
};