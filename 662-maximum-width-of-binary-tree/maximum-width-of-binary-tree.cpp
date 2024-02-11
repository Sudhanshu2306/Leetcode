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
        int ans=0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        
        while(!q.empty()){
            int n=q.size();
            int m=q.front().second;
            int first=0,last=0;

            for(int i=0;i<n;i++){
                int id=q.front().second-m;
                TreeNode* node=q.front().first;
                q.pop();
                if(i==0) first=id;
                if(i==n-1) last=id;

                if(node->left) q.push({node->left,2LL*id+1});
                if(node->right) q.push({node->right,2LL*id+2});

            }
            ans=max(ans,last-first+1);
        }
        return ans;
    }
};