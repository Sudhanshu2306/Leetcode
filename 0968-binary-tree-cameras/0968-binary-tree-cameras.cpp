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
    int camera=0;
    int f(TreeNode* root){
        if(root==nullptr) return 1;

        int lc=f(root->left);
        int rc=f(root->right);

        if(lc==-1 || rc==-1) {
            camera++;
            return 0;
        }
        if(lc==0 || rc==0) return 1;
        return -1;
    }
    int minCameraCover(TreeNode* root) {
        f(root);
        if(root->right==nullptr && root->left==nullptr) camera++;
        return camera;
    }
};