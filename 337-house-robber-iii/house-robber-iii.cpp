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

    pair<int,int> f(TreeNode* root){
        if(root==nullptr) return {0,0};
        if(root->left==nullptr && root->right==nullptr) return {root->val,0};

        pair<int,int> left=f(root->left), right=f(root->right);

        int pick = root->val + left.second + right.second;
        int notpick = 0 + max(left.first,left.second) + max(right.first,right.second);

        return {pick,notpick};
    }

    int rob(TreeNode* root) {
        pair<int,int> ans=f(root);
        return max(ans.first,ans.second);
    }
};