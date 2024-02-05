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

    ListNode* merge(ListNode* h1, ListNode* h2){
        ListNode* h3=new ListNode(INT_MIN);
        ListNode* head=h3;
        while(h1!=nullptr && h2!=nullptr){
            if(h1->val>h2->val){
                head->next=h2;
                h2=h2->next;
            }
            else{
                head->next=h1;
                h1=h1->next;
            }
            head=head->next;
        }
        if(h1!=nullptr){
            head->next=h1; 
        }
        if(h2!=nullptr){
            head->next=h2;
        }
        ListNode* ans=h3->next;
        delete h3;
        return ans;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        ListNode* ans=new ListNode(INT_MIN);
        for(int i=0;i<n;i++){
            merge(ans,lists[i]);
        }
        return ans->next;
    }
};