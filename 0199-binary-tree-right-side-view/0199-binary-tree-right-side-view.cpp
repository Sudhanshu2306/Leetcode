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
    vector<int> rightSideView(TreeNode* root) {
        map<int,int> mp;
        queue<pair<TreeNode*, int>> q;
        q.push({root,0});
        vector<int> ans;
        if(root==nullptr) return ans;
        
        while(!q.empty()){
            auto temp=q.front();
            q.pop();
            TreeNode* node=temp.first;
            int hl=temp.second;
            
            if(mp.find(hl)==mp.end())
                    mp[hl]=node->val;
            if(node->right){
                q.push({node->right,hl+1});
            } 
            if(node->left){
                q.push({node->left,hl+1});
            }
        }
        
        for(auto i:mp){
            ans.push_back(i.second);
        }
        return ans;
    }
};