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
    
    vector<vector<int>> ans;

    void buildVector(TreeNode *root, int depth){
        if(root == NULL) return;
        if(ans.size() == depth)
            ans.push_back(vector<int>());

        ans[depth].push_back(root->val);
        buildVector(root->left, depth + 1);
        buildVector(root->right, depth + 1);
    }
    vector<int> largestValues(TreeNode* root) {
        buildVector(root,0);
        vector<int> answer;
        for(auto i:ans){
            sort(i.begin(),i.end());
            answer.push_back(i.back());
        }
        return answer;
    }
};