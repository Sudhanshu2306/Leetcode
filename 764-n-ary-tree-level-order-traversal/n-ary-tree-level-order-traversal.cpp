/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:

    void lot(Node* root, vector<vector<int>> &ans){
        if(root==nullptr) return;
        queue<Node*> q; q.push(root);
        vector<int> res;
        while(!q.empty()){
            int n=q.size();
            vector<int>arr;
            for(int i=0;i<n;i++){
                Node* temp=q.front(); q.pop();
                for(auto j:temp->children){
                    q.push(j);
                }
                arr.push_back(temp->val);
            }
            ans.push_back(arr);
        }
    }

    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        lot(root,ans);
        return ans;
    }
};