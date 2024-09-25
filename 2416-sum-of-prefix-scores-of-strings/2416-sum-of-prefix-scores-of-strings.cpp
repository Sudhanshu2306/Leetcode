class TrieNode{
    public:
    TrieNode* links[26];
    int prefixCount=0;
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        // sort(words.begin(),words.end());
        TrieNode* root=new TrieNode();
        int n=words.size();

        for(int i=0;i<n;i++){
            TrieNode* node=root;
            for(int j=0;j<words[i].size();j++){
                if(node->links[words[i][j]-'a']==nullptr)
                    node->links[words[i][j]-'a']=new TrieNode();

                node=node->links[words[i][j]-'a'];
                node->prefixCount++;
            }
        }
        vector<int> ans(n);

        for(int i=0;i<n;i++){
            TrieNode* node=root;
            int count=0;
            for(int j=0;j<words[i].size();j++){
                node=node->links[words[i][j]-'a'];
                count+=node->prefixCount;
            }
            ans[i]=count;
        }
        return ans;
    }
};