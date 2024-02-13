/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    void nodeToParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &mp){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* temp=q.front();
            q.pop();
            if(temp->left){
                mp[temp->left]=temp;
                q.push(temp->left);
            }
            if(temp->right){
                mp[temp->right]=temp;
                q.push(temp->right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> mp;
        nodeToParent(root,mp);

        unordered_map<TreeNode*,bool> vis;
        queue<TreeNode*> q;
        q.push(target);

        vis[target]=true;
        int dist=0;
        while(!q.empty()){
            int n=q.size();
            if(dist==k) break;
            for(int i=0;i<n;i++){
                TreeNode* temp=q.front();
                q.pop();

                if(temp->left && !vis[temp->left]){
                    vis[temp->left]=true;
                    q.push(temp->left);
                }
                if(temp->right && !vis[temp->right]){
                    vis[temp->right]=true;
                    q.push(temp->right);
                }
                if(mp[temp] && !vis[mp[temp]]){
                    vis[mp[temp]]=true;
                    q.push(mp[temp]);
                }
            }
            dist++;
        }
        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};