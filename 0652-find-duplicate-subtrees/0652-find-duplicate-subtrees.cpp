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

    vector<int> lOt(TreeNode* root) {
        vector<int> result;
        if(root==nullptr)
            return result;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* current=q.front();
            q.pop();
            if (current) {
                result.push_back(current->val);
                q.push(current->left);
                q.push(current->right);
            } else {
                result.push_back(INT_MIN); 
            }
        }
        return result;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        map<vector<int>,int> mp;
        vector<TreeNode*> res;

        vector<TreeNode*> ans;
        if(root==nullptr) return ans;
        
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            auto temp=q.front();
            q.pop();
            ans.push_back(temp);

            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }

        vector<int> temp;
        for(auto i:ans){
            temp=lOt(i);
            if(mp.find(temp)!=mp.end()){
                if(mp[temp]==1)
                    res.push_back(i);
                
                mp[temp]++;
            } 
            else{
                mp[temp]=1;
            }
            temp.clear();
        }
        return res;
    }
};