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
    unordered_map<TreeNode*, TreeNode*> mp;

    TreeNode* mapping( TreeNode* root, int target){
        TreeNode* res=nullptr;
        mp[root]=nullptr;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode* front=q.front();
            q.pop();
            
            if(front->val==target) res=front;
            
            if(front->left){
                mp[front->left]=front;
                q.push(front->left);
            }
            if(front->right){
                mp[front->right]=front;
                q.push(front->right);
            }
        }
        return res;
    }
    
    int infection(TreeNode* root){
        unordered_map<TreeNode*, bool> vis;
        queue<TreeNode*> q;
        q.push(root);
        vis[root]=1;
        int ans=0;
        while(!q.empty()){
            int flag=0;
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode* front=q.front();
                q.pop();
                
                if(front->left && !vis[front->left]){
                    vis[front->left]=1;
                    q.push(front->left);
                    flag=1;
                }
                if(mp[front] && !vis[mp[front]]){
                    vis[mp[front]]=1;
                    q.push(mp[front]);
                    flag=1;
                }
                if(front->right && !vis[front->right]){
                    vis[front->right]=1;
                    q.push(front->right);
                    flag=1;
                }
            }
            if(flag==1){
                ans++;
            }
        }
        return ans;
    }
    int amountOfTime(TreeNode* root, int start) {
        int ans=0;
        TreeNode* target=mapping(root,start);
        return infection(target);
    }
};