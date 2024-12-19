class Node{
public:
    vector<Node*> child;
    bool flag;

    Node(){
        child.resize(26,nullptr);
        flag=false;
    }
};
class WordDictionary {
private:
    Node* root;
public:
    WordDictionary() {
        root=new Node();
    }
    
    void addWord(string word) {
        Node* node=root;
        for(auto it:word){
            int x=it-'a';
            if(node->child[x]==nullptr) node->child[x]=new Node();
            node=node->child[x];
        }
        node->flag=true;
    }
    
    bool search(string word) {
        Node* node=root;
        for(int i=0;i<word.size();i++){
            int it=word[i];
            if(it=='.'){
                return bfs(word,i,node);
            }
            else{
                if(node->child[it-'a']==nullptr) return false;
                node=node->child[it-'a'];
            }
        }
        return node->flag;
    }
    bool bfs(string word, int start, Node* curr){
        int pos=start;
        queue<Node*> q;
        q.push(curr);

        while(!q.empty() && pos<word.size()){
            int n=q.size();
            for(int i=0;i<n;i++){
                curr=q.front(); q.pop();
                for(int j=0;j<26;j++){
                    if(word[pos]=='.' || j==word[pos]-'a'){
                        if(curr->child[j]!=nullptr){ 
                            if(pos==word.size()-1 && curr->child[j]->flag) return true;
                            q.push(curr->child[j]);
                        }
                    }
                }
            }
            pos++;
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */