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
    int f(TreeNode* node){
        if(node==nullptr) return 0;

        int left=f(node->left);
        int right=f(node->right);
        if(left==-1 || right==-1) return -1;
        if(abs(left-right)>1) return -1;
        return max(left,right)+1;
    }
    // bool isBalanced(TreeNode* root) {
    //     if(root==nullptr) return true;

    //     int leftH=height(root->left);
    //     int rightH=height(root->right);

    //     if(abs(leftH-rightH)>1) return false;

    //     bool left=isBalanced(root->left);
    //     bool right=isBalanced(root->right);

    //     return (left && right);
    // }
    bool isBalanced(TreeNode* root) {
        if(root==nullptr) return true;

        int ans=f(root);
        if(ans==-1) return false; else return true;
    }
};