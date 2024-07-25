class TrieNode{
    public:
        bool flag=false;
        TrieNode * links[26];
};

class Solution {
public:
TrieNode* root;
void insert(string s){
    TrieNode* node=root;
    for(int i=0;i<s.size();i++){
        if(node->links[s[i]-'a']==nullptr) node->links[s[i]-'a']=new TrieNode();
        node=node->links[s[i]-'a'];
    }
    node->flag=true;
}

bool startsWith(string s){
    TrieNode* node=root;
    for(int i=0;i<s.size();i++){
        if(node->links[s[i]-'a']==nullptr) return false;
        if(node->links[s[i]-'a']->flag==false) return false;

        node=node->links[s[i]-'a'];
    }
    return true;
}
    string longestWord(vector<string>& words) {
        sort(words.begin(),words.end());
        root=new TrieNode();

        for(int i=0;i<words.size();i++){
            insert(words[i]);
        }
        int maxi=0;
        string ans="";

        for(int i=0;i<words.size();i++){
            if(startsWith(words[i])){
                if(maxi<words[i].size()){
                    maxi=words[i].size();
                    ans=words[i];
                }
            }
        }
        return ans;
    }
};