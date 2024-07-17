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
    TreeNode* f(TreeNode* root, unordered_set<int> st, vector<TreeNode*> &ans){
        if(root==nullptr) return root;

        TreeNode* left=f(root->left,st,ans);
        TreeNode* right=f(root->right,st,ans);

        if(st.find(root->val)!=st.end()){
            if(left) ans.push_back(left);
            if(right) ans.push_back(right);
            return nullptr;
        }
        root->left=left;
        root->right=right;

        return root;
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> ans;
        if(root==nullptr) return ans;
        int n=to_delete.size();

        unordered_set<int> st(to_delete.begin(),to_delete.end());
        
        TreeNode* node=f(root,st,ans);
        if(node!=nullptr) ans.push_back(node);
        return ans;
    }
};