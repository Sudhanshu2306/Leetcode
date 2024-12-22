class Node{
public:
    vector<Node*> child; bool flag;
    int ind;
    Node(){
        child.resize(27,nullptr); flag=false;
        ind=-1;
    }
};

class Trie{
public:
    Node* root;
    Trie(){
        root=new Node();
    }
    void insert(string s, int i){
        Node* node=root;
        for(auto it:s){
            int x=it-'a';
            if(node->child[x]==nullptr) node->child[x]=new Node();
            node=node->child[x]; node->ind=i;
        }
        node->flag=true;
    }

    int search(string s){
        Node* node=root;
        for(auto it:s){
            int x=it-'a';
            if(node->child[x]==nullptr) return -1;
            node=node->child[x];
        }
        node->flag=true;
        return node->ind;
    }
};
class WordFilter {
public:
    Trie* t;
    WordFilter(vector<string>& words) {
        t=new Trie();
        int j=0;
        for(auto &it:words){
            for(int i=0;i<it.size();i++){
                string x=it.substr(i);
                x+="{"+it;
                t->insert(x,j);
            }
            j++;
        }
    }
    
    int f(string pref, string suff) {
        string y=suff+"{"+pref;
        return t->search(y);
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */