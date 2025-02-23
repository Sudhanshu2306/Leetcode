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
    int x=0;
    TreeNode* f(vector<int> &pre, vector<int> &post, map<int,int> &mp, int i, int j){
        if(i>j) return nullptr;
        TreeNode* root=new TreeNode(pre[x++]);
        if(i==j) return root;
        int ind=mp[pre[x]];

        root->left=f(pre,post,mp,i,ind);
        root->right=f(pre,post,mp,ind+1,j-1);

        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        map<int,int> mp;
        int n=pre.size();
        x=0;
        for(int i=0;i<n;i++) mp[post[i]]=i;
        TreeNode* root=f(pre,post,mp,0,n-1);
        return root;
    }
};