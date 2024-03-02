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

    vector<int> f(TreeNode* root, int distance, int &ans){
        if(root==nullptr) return {};

        if(root->left==nullptr && root->right==nullptr) return {1};

        vector<int> left=f(root->left,distance,ans);
        vector<int> right=f(root->right, distance,ans);

        vector<int> a;
        for(int i:left){
            if(i<=distance) a.push_back(i+1);
        }

        for(int i:right){
            if(i<=distance) a.push_back(i+1);
        }

        for(int i:left){
            for(int j:right){
                if(i+j<=distance) ans++;
            }
        }
        return a;
    }

    int countPairs(TreeNode* root, int distance) {
        int ans=0;
        f(root,distance,ans);
        return ans;
    }
};