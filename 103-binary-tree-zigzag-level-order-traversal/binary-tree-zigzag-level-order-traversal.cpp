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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==nullptr) return ans;
        queue<TreeNode*> q;
        q.push(root);

        bool flag=true;
        while(!q.empty()){
            int x=q.size();
            vector<int> temp;
            for(int i=0;i<x;i++){
                auto it=q.front(); q.pop();
                temp.push_back(it->val);

                if(it->left) q.push(it->left);
                if(it->right) q.push(it->right);
            }
            if(!flag){
                reverse(temp.begin(),temp.end());
            }
            ans.push_back(temp);
            flag=!flag;
        }
        return ans;
    }
};