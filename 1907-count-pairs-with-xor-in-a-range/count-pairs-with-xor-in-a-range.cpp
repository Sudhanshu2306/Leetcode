struct TrieNode{
    TrieNode* children[2];
    int Prenum = 0;
    TrieNode(){
        children[0] = NULL;
        children[1] = NULL;
    }
};

class Trie{
private:
    TrieNode* root;
public:
    Trie(){
        root = new TrieNode();
    }

    void insert(int num){
        TrieNode* crawl = root;
        for(int i=31;i>=0;i--){
            int bit = (num >> i) & 1;
            if(crawl->children[bit] == NULL){
                crawl->children[bit] = new TrieNode();
            }
            crawl = crawl->children[bit];
            crawl->Prenum++;
        }
    }

    int CountLessThanK(int num, int k){
        TrieNode* crawl = root;
        int count = 0;
        for(int i=31;i>=0;i--){
            if(!crawl) break;

            int numBit = (num >> i) & 1;
            int kBit = (k >> i) & 1;

            if(kBit == 1){
                if(crawl->children[numBit]){
                    count += crawl->children[numBit]->Prenum;
                }
                crawl = crawl->children[!numBit];
            }else{
                crawl = crawl->children[numBit];
            }
        }

        return count;
    }
};
class Solution {
public:
    int countPairs(vector<int>& nums, int low, int high) {
        Trie t;
        int result = 0;
        for(auto num:nums){
            result += (t.CountLessThanK(num, high+1) - t.CountLessThanK(num, low));
            t.insert(num);
        }

        return result;
    }
};