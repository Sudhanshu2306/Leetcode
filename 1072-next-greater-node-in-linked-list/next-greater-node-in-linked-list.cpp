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

    vector<int> f(vector<int>& ans){
        int n=ans.size();
        stack<int> st;
        st.push(ans[n-1]);
        ans[n-1]=0;
        for(int i=n-2;i>=0;i--){
            while(!st.empty() && ans[i]>=st.top()) st.pop();
            int temp=ans[i];
            if(st.empty()) ans[i]=0;
            else ans[i]=st.top();

            st.push(temp);
        }
        return ans;
    }

    vector<int> nextLargerNodes(ListNode* head) {
        ListNode* temp=head;
        vector<int> ans;
        while(temp!=nullptr){
            ans.push_back(temp->val);
            temp=temp->next;
        }
        return f(ans);
    }
};