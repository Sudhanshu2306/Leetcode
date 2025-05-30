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
class BSTIterator {
public:
    stack<TreeNode*> st;
    BSTIterator(TreeNode* root) {
        while(true){
            if(root!=nullptr){
                st.push(root);
                root=root->left;
            }
            else break;
        }
    }
    
    int next() {
        TreeNode* x=st.top(); st.pop();
        if(x->right){
            TreeNode* y=x->right;
            while(true){
                if(y){
                    st.push(y);
                    y=y->left;
                } 
                else break;
            }
        }
        return x->val;
    }
    
    bool hasNext() {
        if(!st.empty()) return true;
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */