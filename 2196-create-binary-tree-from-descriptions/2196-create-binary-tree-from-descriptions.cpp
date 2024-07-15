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
    TreeNode* createBinaryTree(vector<vector<int>>& des) {
        int n=des.size();
        int val;
        unordered_set<int> st;
        map<int,vector<pair<int,int>>> mp;
        for(int i=0;i<n;i++){
            mp[des[i][0]].push_back({des[i][1],des[i][2]});
            st.insert(des[i][1]);
        }
        for(int i=0;i<n;i++){
            int x=des[i][0];
            if(st.find(x)==st.end()){
                val=x; break;
            }
        }
        TreeNode* root=new TreeNode(val);
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            auto node=q.front();
            q.pop();

            int x=node->val;

            for(auto i:mp[x]){
                if(i.second==1){
                    TreeNode* l=new TreeNode(i.first);
                    q.push(l);
                    node->left=l;
                } 
                else {
                    TreeNode* r=new TreeNode(i.first);
                    q.push(r);
                    node->right=r;
                }
            }
        }
        return root;
    }
};