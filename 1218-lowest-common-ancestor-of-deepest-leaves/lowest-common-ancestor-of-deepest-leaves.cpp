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
 typedef long long ll;
class Solution {
public:
    ll x=-1e18;
    TreeNode* ans;
    ll ff(TreeNode* root, ll d){
        if(root==nullptr) return d;
        ll left=ff(root->left,d+1);
        ll right=ff(root->right,d+1);

        if(left==right){
            x=max(x,left);
            if(x==left) ans=root;
        }
        return max(left,right);
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        ff(root,0);
        return ans;
    }
};