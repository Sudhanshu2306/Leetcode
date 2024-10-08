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
    void f(Node* root, vector<int> &ans){
        if(root==nullptr) return;

        ans.push_back(root->val);
        int n=root->children.size();
        for(int i=0;i<n;i++){
            f(root->children[i],ans);
        }
        
    }

    vector<int> preorder(Node* root) {
        vector<int> ans;
        f(root,ans);
        return ans;
    }
};