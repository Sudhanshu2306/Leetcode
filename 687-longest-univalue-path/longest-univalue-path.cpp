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
    int dfs(TreeNode* root, int &maxi){
        int left=0, right=0;
        if(root->left) left=dfs(root->left,maxi);
        if(root->right) right=dfs(root->right,maxi);

        if(root->left && root->left->val==root->val) left++;
        else left=0;
        if(root->right && root->right->val==root->val) right++;
        else right=0;
        maxi=max(maxi,left+right);

        return max(left,right);
    }
    int longestUnivaluePath(TreeNode* root) {
        if(root==nullptr) return 0;
        int maxi=0;
        dfs(root,maxi);
        return maxi;
    }
};