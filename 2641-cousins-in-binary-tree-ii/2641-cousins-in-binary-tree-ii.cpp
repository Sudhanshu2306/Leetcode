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
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<TreeNode*> q; q.push(root);
        queue<int> s;
        while(!q.empty()){
            int n=q.size(); int sum=0;
            for(int i=0;i<n;i++){
                auto x=q.front(); q.pop();
                sum+=x->val;
                if(x->left) q.push(x->left);
                if(x->right) q.push(x->right);
            }
            s.push(sum);
        }
        queue<pair<TreeNode*,TreeNode*>> qq; qq.push({root,nullptr});
        int ind=0;
        while(!qq.empty()){
            int sum=s.front(); s.pop();
            int n=qq.size(); 
            for(int i=0;i<n;i++){
                auto x=qq.front(); qq.pop();
                TreeNode* left=x.first;
                TreeNode* right=x.second;
                int leftVal=0,rightVal=0;
                if(left!=nullptr) {
                    leftVal=left->val;
                    qq.push({left->left,left->right});
                }
                if(right!=nullptr) {
                    rightVal=right->val;
                    qq.push({right->left,right->right});
                }
                if(left!=nullptr) left->val=sum-leftVal-rightVal;
                if(right!=nullptr) right->val=sum-leftVal-rightVal;
            }
            ind++;
        }
        return root;
    }
};