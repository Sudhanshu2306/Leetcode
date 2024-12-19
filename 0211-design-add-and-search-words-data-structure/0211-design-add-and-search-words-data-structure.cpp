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
        set<pair<Node*,int>> vis;
        queue<pair<Node*, int>> q;
        q.push({root,0});
        vis.insert({root,0});

        while(!q.empty()){
            auto x=q.front(); q.pop();
            Node* node=x.first; int ind=x.second;

            if(word.size()==ind){
                if(node->flag==true) return true;
                continue;
            }

            char it=word[ind];
            if(it=='.'){
                for(int i=0;i<26;i++){
                    if(node->child[i]!=nullptr && vis.find({node->child[i],ind+1})==vis.end()){
                        q.push({node->child[i],ind+1});
                        vis.insert({node->child[i],ind+1});
                    }
                }
            }
            else{
                if(node->child[it-'a']!=nullptr && vis.find({node->child[it-'a'],ind+1})==vis.end()){
                    q.push({node->child[it-'a'],ind+1});
                    vis.insert({node->child[it-'a'],ind+1});
                } 
                    
            }
        
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