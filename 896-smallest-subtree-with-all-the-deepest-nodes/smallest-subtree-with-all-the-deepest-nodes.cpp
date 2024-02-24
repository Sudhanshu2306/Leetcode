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
    int maxi=INT_MIN;
    TreeNode* res=nullptr;
    int f(TreeNode* root, int depth){
        if(root==nullptr) return depth;
        int left=f(root->left,depth+1);
        int right=f(root->right,depth+1);
        if(left==right){
            maxi=max(maxi,left);
            if(maxi==left){
                res=root;
            }
        }
        return max(left,right);
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        f(root,0);
        return res;
    }
};