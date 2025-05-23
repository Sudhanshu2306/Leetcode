class Node{
public:
    vector<Node*> child;
    bool flag;
    Node(){
        child.resize(26,nullptr);
        flag=false;
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
    int search(string s){
        Node* node=root;
        int len=1;
        for(auto it:s){
            int x=it-'a';
            if(node->child[x]==nullptr) return -1;
            node=node->child[x];
            if(node->flag) return len;
            len++;
        }
        return -1;
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string s) {
        Trie t;
        for(auto it:dictionary){
            t.insert(it);
        }
        string ans="";
        int i=0;
        int n=s.size();
        while(i<n){
            string x;
            while(i<n && s[i]!=' ') x+=s[i++];
            int size=t.search(x);

            if(size==-1) ans+=x;
            else ans+=x.substr(0,size);
            if(i<n) ans+=s[i++];
        }
        return ans;
    }
};