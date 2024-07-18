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
    vector<int> f(TreeNode* root, int distance, int &count){
        vector<int> a;
        if(root==nullptr) return {};

        if(root->left==nullptr && root->right==nullptr) return {1};

        vector<int> left=f(root->left,distance,count);
        vector<int> right=f(root->right,distance,count);

        for(int i=0;i<left.size();i++){
            if(left[i]<=distance) a.push_back(left[i]+1);
        }
        for(int i=0;i<right.size();i++){
            if(right[i]<=distance) a.push_back(right[i]+1);
        }

        for(int i=0;i<left.size();i++){
            for(int j=0;j<right.size();j++){
                if(left[i]+right[j]<=distance) count+=1;
            }
        }
        return a;
    }
    int countPairs(TreeNode* root, int distance) {
        int count=0;
        f(root,distance,count);
        return count;
    }
};