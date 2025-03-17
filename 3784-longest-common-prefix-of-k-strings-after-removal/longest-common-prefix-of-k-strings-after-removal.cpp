class Node{
    public:
    vector<Node*> link;
    bool flag;
    int count;

    Node(){
        link.resize(26,nullptr);
        flag=false; count=0;
    }
};

class Trie{
    public:
    Node* root;
    Trie(){
        root=new Node();
    }
    void insert(string s, map<int,int> &mp, int k){
        Node* node=root;
        for(int i=0;i<s.size();i++){
            if(node->link[s[i]-'a']==nullptr) node->link[s[i]-'a']=new Node();
            node=node->link[s[i]-'a'];
            node->count++;

            if(node->count>=k && !node->flag){
                node->flag=true;
                mp[i+1]++;
            }
        }
    }
    void erase(string s, map<int,int> &mp, int k){
        Node* node=root;
        for(int i=0;i<s.size();i++){
            if(node->link[s[i]-'a']==nullptr) node->link[s[i]-'a']=new Node();
            node=node->link[s[i]-'a'];
            node->count--;

            if(node->count<k && node->flag){
                node->flag=false;
                mp[i+1]--;
                if(mp[i+1]==0) mp.erase(i+1);
            }
        }
    }
};

class Solution {
public:
    vector<int> longestCommonPrefix(vector<string>& words, int k) {
        int n=words.size();
        Trie t;
        map<int,int> mp;
        for(auto it:words){
            t.insert(it,mp,k);
        }
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            t.erase(words[i],mp,k);
            if(mp.size()>0){
                ans[i]=prev(mp.end())->first;
            }
            else ans[i]=0;
            t.insert(words[i],mp,k);
        }
        return ans;
    }
};