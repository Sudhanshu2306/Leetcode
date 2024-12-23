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
    int minimumOperations(TreeNode* root) {
        vector<vector<int>> x;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int n=q.size();
            vector<int> y;
            for(int i=0;i<n;i++){
                auto temp=q.front(); q.pop();
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
                y.push_back(temp->val);
            }
            x.push_back(y);
        }
        int ans=0;
        for(auto it:x){
            vector<vector<int>> arr;
            map<int,int> mp;
            for(int i=0;i<it.size();i++) arr.push_back({it[i],i});
            sort(arr.begin(),arr.end());
            for(int i=0;i<arr.size();i++) mp[arr[i][0]]=i;

            for(int i=0;i<it.size();i++){
                if(i!=arr[i][1]){
                    ans++;
                    arr[mp[it[i]]][1]=arr[i][1];
                    swap(it[i],it[arr[i][1]]);
                    arr[i][1]=i;
                }
            }
        }
        return ans;
    }
};