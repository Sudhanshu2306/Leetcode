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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL && list2==NULL)
            return NULL;
        
        if(list1==NULL)
            return list2;
        
        if(list2==NULL)
            return list1;

        ListNode* temp1=list1;
        ListNode* temp1prev=list1;
        ListNode* temp2=list2;
        while(temp1!=NULL && temp2!=NULL){
            if(temp1->val<=temp2->val){
                temp1prev=temp1;
                temp1=temp1->next;
            }
            else{
                list2=list2->next;
                temp2->next=temp1;
                if(list1->val > temp2->val){
                    list1=temp2;
                }
                if (temp1 != temp1prev){
                    temp1prev->next = temp2;
                    temp1prev = temp1prev->next;
                }
                else{
                    temp1prev=list1;
                }
                temp2=list2;
            }
        }
        if(temp2!=NULL){
            temp1prev->next=temp2;
        }
        return list1;
    }
};