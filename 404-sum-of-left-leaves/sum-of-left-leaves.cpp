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
    void f(TreeNode* root, int &sum){
        if(root==nullptr) return;

        f(root->left,sum);
        if(root->left){
            if(root->left->left==nullptr && root->left->right==nullptr) sum+=root->left->val;
        } 
        f(root->right,sum);
    }

    int sumOfLeftLeaves(TreeNode* root) {
        // if(root->left==nullptr && root->right==nullptr) return 0;
        int ans=0;
        f(root,ans);
        return ans;
    }
};