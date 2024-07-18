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
    // A little change here, return type is pair<int,int> instead of unconventional int type
    // this makes the solution easier

    // pair<int,int> represents node when robbed and when not robbed
    pair<int,int> f(TreeNode* root, map<TreeNode*,pair<int,int>> &dp){
        if(root==nullptr) return {0,0};

        auto left=f(root->left,dp);
        auto right=f(root->right,dp);

        pair<int,int> ans;
        // when we take the node, and not take the immediate childs
        ans.first=root->val+left.second+right.second;
        ans.second=max(left.first,left.second)+max(right.first,right.second);

        return dp[root]=ans;
    }

    int rob(TreeNode* root) {
        map<TreeNode*,pair<int,int>> dp;
        pair<int,int> res=f(root,dp);
        return max(res.first,res.second);
    }
};