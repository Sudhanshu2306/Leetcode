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
    vector<vector<int>> spiralMatrix(int n, int m, ListNode* head) {
        int sr=0,er=n-1;
        int sc=0,ec=m-1;
        vector<vector<int>> ans(n,vector<int>(m,-1));
        while(head!=nullptr){
            for(int i=sc;head && i<=ec;i++){
                ans[sr][i]=head->val; head=head->next;
            }
            sr++;
            for(int i=sr;head && i<=er;i++){
                ans[i][ec]=head->val; head=head->next;
            }
            ec--;
            for(int i=ec;head && i>=sc;i--){
                ans[er][i]=head->val; head=head->next;
            }
            er--;
            for(int i=er;head && i>=sr;i--){
                ans[i][sc]=head->val; head=head->next;
            }
            sc++;
        }
        return ans;
    }
};