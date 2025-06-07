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
    int f(TreeNode* root, int maxi){
        if(root==nullptr) return 0;
        int count=0;
        if(root->val>=maxi){
            count++; maxi=root->val;
        } 
        return count+f(root->left,maxi)+f(root->right,maxi);
    }
    int goodNodes(TreeNode* root) {
        int maxi=root->val;
        return f(root, maxi);
        
    }
};