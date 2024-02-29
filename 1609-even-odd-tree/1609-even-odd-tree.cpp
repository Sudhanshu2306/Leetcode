/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    vector<int> lOt(TreeNode* root){
        vector<int> ans;
        if(root==nullptr) return ans;
        
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int n=q.size();

            for(int i=0;i<n;i++){
                auto temp=q.front();
                q.pop();
                ans.push_back(temp->val);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            ans.push_back(INT_MIN);
        }
        return ans;
    }

    bool isEvenOddTree(TreeNode* root) {
        vector<int> ans=lOt(root);
        int n=ans.size();
        int level=0;
        int prev=(level%2==0)?INT_MIN:INT_MAX;

        for(int val:ans){
            if(val==INT_MIN){ 
                level++;
                prev=(level%2==0)?INT_MIN:INT_MAX; 
            } 
            else{
                if((level%2==0 && (val%2==0||val<=prev)) ||
                    (level%2==1 && (val%2==1 || val>=prev))){ 
                    return false;
                }
                prev=val; 
            }
        }
        return true;
    }
};