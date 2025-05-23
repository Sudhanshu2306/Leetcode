class Node{
    public:
    vector<Node*> links;
    bool flag;
    Node(){
        links.resize(26,nullptr);
        this->flag=false;
    }
};
class Trie{
    public:
    Node* root;
    Trie(){
        root=new Node();
    }

    void insert(string x){
        Node* curr=root;
        for(auto it:x){
            if(curr->links[it-'a']==nullptr) curr->links[it-'a']=new Node();
            curr=curr->links[it-'a'];
        }
        curr->flag=true;
    }
    int search(string x){
        Node* curr=root;
        int i=0;
        for(auto it:x){
            if(curr->links[it-'a']==nullptr) return -1;
            curr=curr->links[it-'a'];
            if(curr->flag) return i;
            i++;
        }
        return -1;
    }
};

class Solution {
public:
    string replaceWords(vector<string>& d, string s) {
        Trie t;
        for(auto it:d) t.insert(it);

        stringstream ss(s);
        string word;
        string ans="";
        while(ss>>word){
            int i=t.search(word);
            string y=word.substr(0,i+1);
            if(i!=-1) ans+=y; 
            else ans+=word;
            ans+=" ";
        }
        int n=ans.size();
        return ans.substr(0,n-1);
    }
};