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
    TreeNode* solve(int& idx,int start,int end,vector<int>& inorder,vector<int>& postorder, map<int,int> &mp){
        if(start>end || idx<0){
            return NULL;
        }
        int element=postorder[idx]; idx--;
        int pos=mp[element];
        TreeNode* root=new TreeNode(element);

        root->right=solve(idx,pos+1,end,inorder,postorder,mp);
        root->left=solve(idx,start,pos-1,inorder,postorder,mp);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode* root;
        int n=inorder.size();
        int lastpos=n-1;
        map<int,int> mp;
        for(int i=0;i<n;i++) mp[inorder[i]]=i;
        root=solve(lastpos,0,n-1,inorder,postorder,mp);
        return root;
    }
};