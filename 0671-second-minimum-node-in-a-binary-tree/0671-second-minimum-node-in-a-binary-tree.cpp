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
    void inorder(TreeNode* root, int &mini, long long &smini){
        if(root==nullptr) return;

        if(mini<root->val && root->val<smini) smini=root->val;
        else if(mini==root->val){
            inorder(root->left,mini,smini);
            inorder(root->right,mini,smini);
        }
    }
    int findSecondMinimumValue(TreeNode* root) {
        int mini=root->val;
        long long smini=LLONG_MAX;
        inorder(root,mini,smini);
        return smini==LLONG_MAX?-1:smini;
    }
};