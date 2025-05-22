class Node{
    public:
    // this is same as taking a vector of two pointers for storing 0 and 1
    Node* left; 
    Node* right;
    int count;

    Node(){
        this->left=nullptr;
        this->right=nullptr;
        this->count=0;
    }
};
class Trie{
    public:
    Node* root;

    Trie(){
        root=new Node();
    }

    void insert(int x){
        for(int i=14;i>=0;i--){
            int bit=(x & (1<<i)); // finding set bit at particualr index

            if(bit==0){
                if(root->left==nullptr) root->left=new Node();
                root=root->left;
            }
            else{
                if(root->right==nullptr) root->right=new Node();
                root=root->right;
            }
            root->count++;
        }
    }
    int getCount(Node* root){
        return (root==nullptr)? 0:root->count;
    }
    int query(int limit, int val, int i){
        if(root==nullptr) return 0; // base case

        if(i==-1) return getCount(root);
        int bitv=(val & (1<<i)); 
        int bitl=(limit & (1<<i));

        if(bitv==0){
            if(bitl==0){
                return query(limit, val, i-1);
            }
            else{
                return getCount(root->left)+query(limit,val,i-1);
            }
        }
        else{
            if(bitl==0) return query(limit,val,i-1); 
            else return getCount(root->right)+query(limit,val,i-1);
        }
    }
};

class Solution {
public:
    int countPairs(vector<int>& nums, int low, int high) {
        int n=nums.size();
        long long count=0;
        Trie *t=new Trie();
        for(int i=0;i<n;i++){
            count+=t->query(high, nums[i], 14);
            count+=t->query(low-1, nums[i], 14);
            t->insert(nums[i]);
        }
        return count;
    }
};