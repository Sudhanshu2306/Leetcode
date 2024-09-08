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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        vector<ListNode*> ans(k, nullptr);
        ListNode* temp=root;
        int n=0;

        while(temp!=nullptr){
            n++;
            temp=temp->next;
        }
        int x=n/k;
        int y=n%k;

        temp = root;
        ListNode* prev = nullptr;

        for (int i=0;temp && i<k;i++) {
            ans[i]=temp;
            int ll=x+(y>0);  
            for(int j=0;j<ll;j++){
                prev=temp;
                temp=temp->next;
            }
            if(prev!=nullptr) prev->next=nullptr;
            y--;
        }
        return ans;
    }
};