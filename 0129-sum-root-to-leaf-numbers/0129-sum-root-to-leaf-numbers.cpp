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

    void f(TreeNode* root, int sum, int &res){
        if(root->left==nullptr && root->right==nullptr){
            res+=(root->val+sum*10);
        }
        if(root->left) f(root->left,root->val+sum*10,res);
        if(root->right) f(root->right,root->val+sum*10,res); 
    }
    int sumNumbers(TreeNode* root) {
        vector<int> ans;
        int res=0;
        int sum=0;
        f(root,sum,res);
        return res;
    }
};