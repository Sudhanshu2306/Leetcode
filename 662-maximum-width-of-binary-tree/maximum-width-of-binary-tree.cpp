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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==nullptr) return 0;
        queue<pair<TreeNode*,long long>> q;
        q.push({root,0});
        long long maxi=0;
        while(!q.empty()){
            int n=q.size();  
            long long first=0,last=0;
            for(int i=0;i<n;i++){
                int id=q.front().second;
                TreeNode* node=q.front().first;
                q.pop();
                if(i==0) first=id;
                if(i==n-1) last=id;

                if(node->left) q.push({node->left,2LL*id+1});
                if(node->right) q.push({node->right,2LL*id+2});

            } 
            maxi=max(maxi,last-first+1);
        }
        return maxi;
    }
};