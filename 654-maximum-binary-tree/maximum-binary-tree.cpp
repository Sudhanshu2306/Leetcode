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

    int maxInd(vector<int>& nums,int i,int j){
        int maxi=INT_MIN;
        int ind=i;
        for(int x=i;x<=j;x++){
            if(maxi<nums[x]){
                maxi=nums[x];
                ind=x;
            }
        }return ind;
    }

    TreeNode* f(vector<int>& nums, int i, int j){
        if(i>j) return nullptr;
        if(i==j) return new TreeNode(nums[j]);

        int ind=maxInd(nums,i,j);
        TreeNode* root=new TreeNode(nums[ind]);

        root->left=f(nums,i,ind-1);
        root->right=f(nums,ind+1,j);

        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n=nums.size();
        return f(nums,0,n-1);
    }
};