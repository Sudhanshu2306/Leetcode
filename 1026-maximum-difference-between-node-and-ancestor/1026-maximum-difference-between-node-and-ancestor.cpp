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
    int diff=0;
    
    void solve(TreeNode *root, int maxi, int mini){
        if(root==nullptr)
            return;
        diff=max(diff,max(abs(maxi-root->val),abs(root->val-mini)));
        
        mini=min(mini,root->val);
        maxi=max(root->val,maxi);
        
        solve(root->left,maxi,mini);
        solve(root->right,maxi,mini);

    }
    
    int maxAncestorDiff(TreeNode* root) {
        int maxi=root->val; int mini=root->val;
        solve(root,maxi,mini);
        return diff;
    }
};