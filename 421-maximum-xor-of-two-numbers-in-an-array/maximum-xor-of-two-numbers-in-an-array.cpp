class TrieNode{
    public:
    TrieNode* links[2];

};

class Trie{
    private:
    TrieNode* root;
    public: 
        Trie(){
            root=new TrieNode();
        }
    public:
    // insert the number into trie in form of bits
        void insert(int num){
            TrieNode* node=root;
            for(int i=31;i>=0;i--){
                int bit=(num>>i)&1; // either 0 or 1
                if(node->links[bit]==nullptr) {
                    node->links[bit]=new TrieNode();
                }
                node=node->links[bit];
            }
        }

        int getMax(int num){
            TrieNode* node=root;
            int maxi=0;
            for(int i=31;i>=0;i--){
                int bit=(num>>i) & 1;
                if(node->links[1-bit]!=nullptr){
                    maxi= maxi | (1<<i);
                    node=node->links[1-bit];
                }
                else{
                    node=node->links[bit];
                }
            }
            return maxi;
        }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        for(int i=0;i<nums.size();i++){
            trie.insert(nums[i]);
        }
        int maxi=0;
        for(int i=0;i<nums.size();i++){
            maxi=max(maxi,trie.getMax(nums[i]));
        }
        return maxi;
    }
};