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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level=0;

        while(!q.empty()){
            int n=q.size();
            vector<TreeNode*> ans;

            for(int i=0;i<n;i++){
                auto temp=q.front();
                q.pop();
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);

                if(level%2==1) ans.push_back(temp);
            }
            if(level%2==1){
                int x=ans.size()/2;
                for(int i=0;i<x;i++){
                    swap(ans[i]->val,ans[ans.size()-i-1]->val);
                }
            }
            level+=1;
        }
        return root;
    }
};