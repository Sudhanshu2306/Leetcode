class Node{
public:
    vector<Node*> children;
    bool flag;

    Node(){
        children.resize(26,nullptr);
        flag=false;
    }
};
class Trie {
private:
Node* root;
public:
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        Node* node=root;
        for(int i=0;i<word.size();i++){
            int x=word[i]-'a';
            if(node->children[x]==nullptr) node->children[x]=new Node();
            node=node->children[x];
        }
        node->flag=true;
    }
    
    bool search(string word) {
        Node* node=root;
        for(int i=0;i<word.size();i++){
            int x=word[i]-'a';
            if(node->children[x]==nullptr) return false;
            node=node->children[x];
        }
        return node->flag;
    }
    
    bool startsWith(string prefix) {
        Node* node=root;
        for(int i=0;i<prefix.size();i++){
            int x=prefix[i]-'a';
            if(node->children[x]==nullptr) return false;
            node=node->children[x];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */