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
    
    void paths(TreeNode* root, vector<int> &count, int &res){
        if(root==nullptr) return;

        count[root->val]++;
        if(root->left==nullptr && root->right==nullptr){
            int odd=0;
            for(int i=1;i<=9;i++){
                if(count[i]%2==1) odd++;
            }
            if(odd==1 || odd==0) res++; 
        }
        else{
            paths(root->left,count,res);
            paths(root->right,count,res);
        }
        count[root->val]--;
    }

    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> count(10,0);
        int res=0;
        paths(root,count,res);
        return res;
    }
};