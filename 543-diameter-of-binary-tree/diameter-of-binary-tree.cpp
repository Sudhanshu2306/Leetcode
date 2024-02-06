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
    int solve(TreeNode* root,int &maxi){
        if(root==nullptr) return 0;

        int left=solve(root->left,maxi);
        int right=solve(root->right,maxi);
        maxi=max(maxi,left+right);
        return 1+max(left,right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi=INT_MIN;
        int x=solve(root,maxi);
        return maxi;
    }
    /*
    int maxi=INT_MIN;
    int height(TreeNode* root){
        if(root==nullptr) return 0;
        int left=height(root->left);
        int right=height(root->right);
        return 1+max(left,right);
    }

    
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==nullptr) return 0;
        int leftH=height(root->left);
        int rightH=height(root->right);

        int leftD=diameterOfBinaryTree(root->left);
        int rightD=diameterOfBinaryTree(root->right);

        return max({leftD,rightD,leftH+rightH});
    }
    */
};