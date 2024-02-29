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

    bool f(TreeNode* root, int x){
        if(root->left==nullptr && root->right==nullptr) return true;

        bool left=true, right=true;
        if(root->left){
            if(root->left->val==x) left=f(root->left,x);
            else left=false;
        } 
        if(root->right){
            if(root->right->val==x) right=f(root->right,x);
            else right=false;
        }
        return left&&right;
    }

    bool isUnivalTree(TreeNode* root) {
        int x=root->val;
        return f(root, x);
    }
};