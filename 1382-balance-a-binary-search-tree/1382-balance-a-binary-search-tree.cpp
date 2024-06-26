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
    void inorder(TreeNode* root, vector<int> &ans){
        if(root==nullptr) return;
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
    TreeNode* f(int s, int e, vector<int> &ans){
        if(s>e) return nullptr;

        int mid=s+(e-s)/2;
        TreeNode* root=new TreeNode(ans[mid]);
        root->left=f(s,mid-1,ans);
        root->right=f(mid+1,e,ans);

        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> ans;
        inorder(root, ans);

        return f(0,ans.size()-1,ans);
    }
};