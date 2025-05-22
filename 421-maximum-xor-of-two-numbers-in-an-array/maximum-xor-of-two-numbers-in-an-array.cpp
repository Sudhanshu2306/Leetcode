class Node{
    public:
    vector<Node*> links;

    Node(){
        links.resize(2);
        links[0]=links[1]=nullptr;
    }   
};
class Trie{
    public:
    Node* root;
    Trie(){
        root=new Node();
    }

    void insert(int x){
        Node* curr=root;
        for(int i=31;i>=0;i--){
            int bit=(x>>i)&1;
            if(curr->links[bit]==nullptr) curr->links[bit]=new Node();
            curr=curr->links[bit];
        }
    }
    int f(int x){
        Node* curr=root;
        int maxi=0;
        for(int i=31;i>=0;i--){
            int bit=(x>>i)&1;
            if(curr->links[1-bit]==nullptr) curr=curr->links[bit];
            else{
                maxi=maxi|(1<<i);
                curr=curr->links[1-bit];
            }
        }
        return maxi;
    }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie t;
        for(auto it:nums) t.insert(it);
        int maxi=0;
        for(auto it:nums) maxi=max(maxi,t.f(it));
        return maxi;
    }
};