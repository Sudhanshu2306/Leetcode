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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> track;
    //  vertical - level -  number of nodes
        vector<vector<int>> ans;
        if(root == nullptr) return ans;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto temp=q.front();
            q.pop();

            TreeNode* node=temp.first;
            int v = temp.second.first;
            int h = temp.second.second;
            track[v][h].insert(node->val);
            if(node->left) 
                q.push({node->left,{v-1,h+1}});
            if(node->right)
                q.push({node->right,{v+1,h+1}});
        }

        for(auto i:track){
            vector<int> sAns;
            for(auto j:i.second){
                sAns.insert(sAns.end(), j.second.begin(),j.second.end());
            }
            ans.push_back(sAns);
        }
        return ans;
    }
};