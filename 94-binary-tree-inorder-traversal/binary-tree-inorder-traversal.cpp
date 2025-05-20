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
    
    void inorder(TreeNode* root, vector<int>&ans){
        if(root==NULL){
            return;
        }
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        // inorder(root,ans);
        TreeNode* curr=root;
        while(curr!=nullptr){
            if(curr->left==nullptr){
                ans.push_back(curr->val);
                curr=curr->right;
            }
            else{
                TreeNode* p=curr->left;
                while(p->right!=nullptr && p->right!=curr){
                    p=p->right;
                }
                if(p->right==nullptr){
                    p->right=curr;
                    curr=curr->left;
                }
                else{
                    p->right=nullptr;
                    ans.push_back(curr->val);
                    curr=curr->right;
                }
            }
        }
        return ans;
    }
};