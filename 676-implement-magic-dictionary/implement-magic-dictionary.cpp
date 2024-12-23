class Node{
public:
    vector<Node*> child;
    bool flag;
    int count;
    Node(){
        child.resize(26,nullptr);
        flag=false;
        count=0;
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
        for(auto it:s){
            int x=it-'a';
            if(node->child[x]==nullptr) node->child[x]=new Node();
            node=node->child[x];
        }
        node->flag=true;
    }

    bool search(string s){
        return ff(root,s,0,false);
    }
    bool ff(Node* node, string &s, int index, bool flag) {
        if(index==s.size()) return flag && node->flag;
        int x=s[index]-'a';
        for(int i=0;i<26;i++){
            if(node->child[i]==nullptr) continue;
            if(i==x){
                if(ff(node->child[i],s,index+1,flag)) return true;
            } 
            else if(!flag){ 
                if(ff(node->child[i],s,index+1,true)) return true;
            }
        }
        return false;
    }
};

class MagicDictionary {
public:
    Trie* t;
    MagicDictionary() {
        t=new Trie();
    }
    
    void buildDict(vector<string> dictionary) {
        for(auto it:dictionary){
            t->insert(it);
        }
    }
    
    bool search(string searchWord) {
        return t->search(searchWord);
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */