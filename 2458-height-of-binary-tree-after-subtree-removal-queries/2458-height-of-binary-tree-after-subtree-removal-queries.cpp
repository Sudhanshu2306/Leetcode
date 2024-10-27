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
int level[1000001]; //level of each node
int height[100001]; //height of each level
int levelmaxht[100001];
int levelsecmaxht[100001]; 

int findheight(TreeNode* root,int lev)
{
    if(!root) return 0;
    level[root->val]=lev;
height[root->val]=max(findheight(root->left,lev+1),findheight(root->right,lev+1))+1;
if(levelmaxht[lev] < height[root->val])
{
    levelsecmaxht[lev]=levelmaxht[lev];
    levelmaxht[lev]=height[root->val];
}
else if(levelsecmaxht[lev] < height[root->val])
{
levelsecmaxht[lev]=height[root->val];
}
return height[root->val];
}

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
       findheight(root,0); 
       vector<int>res;
       for(int &node:queries)
       {
        //node that we have to delete
        int l=level[node]; //nodelevel
        //l + h - 1
    int temres=l+(levelmaxht[l]==height[node] ? levelsecmaxht[l] : levelmaxht[l] )-1;
        res.push_back(temres);
       }
       return res;
    }
};