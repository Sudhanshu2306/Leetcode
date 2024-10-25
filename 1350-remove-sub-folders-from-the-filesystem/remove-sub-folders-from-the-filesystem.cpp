struct Node{
    bool flag;
    Node* links[27];

    Node(){
        this->flag=false;
        for(int i=0;i<27;i++) links[i]=nullptr;
    }
};
class Trie{
public:
    Node* root;
    Trie(){
        root=new Node();
    }
    void insert(string s){
        Node* node=root;
        for(int i=0;i<s.size();i++){
            int ind=(s[i]=='/')?26:s[i]-'a';
            if(node->links[ind]==nullptr) node->links[ind]=new Node();
            node=node->links[ind];
        }
        node->flag=true;
    }
    bool search(string s){
        Node* node=root;
        for(int i=0;i<s.size();i++){
            int ind=(s[i]=='/')?26:s[i]-'a';
            if(node->links[ind]==nullptr) return false;
            node=node->links[ind];
            if(node->flag && i<s.size()-1 && s[i+1]=='/') return false;
        }
        return true;
    }
};
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string> ans;
        Trie trie;
        for(auto it:folder){
            trie.insert(it);
        }
        for(auto it:folder){
            if(trie.search(it)) ans.push_back(it);
        }
        return ans;
    }
};