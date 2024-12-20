class Node{
public:
    vector<Node*> child;
    string z;
    Node(){
        child.resize(26,nullptr); z="";
    }
};

class Trie{
private:
public:
    Node* root;
    Trie(){
        root=new Node();
    }

    void insert(string s){
        Node* node=root;
        string y="";
        for(auto it:s){
            int x=it-'a';
            y+=it;
            if(node->child[x]==nullptr) node->child[x]=new Node();
            node=node->child[x];
        }
        node->z=s;
    }
};

class Solution {
public:
    int dx[4]={0,-1,0,1};
    int dy[4]={1,0,-1,0};

    void dfs(int i, int j, vector<vector<char>>& board, Node* root, vector<string> &ans, vector<vector<int>> &vis){
        Node* child=root->child[board[i][j]-'a'];
        if(child==nullptr) return;

        if(child->z!=""){
            ans.push_back(child->z);
            child->z="";
        }
        int n=board.size(); int m=board[0].size();
        vis[i][j]=1;
        for(int k=0;k<4;k++){
            int ni=i+dx[k];
            int nj=j+dy[k];

            if(ni>=0 && ni<n && nj>=0 && nj<m && vis[ni][nj]==0) dfs(ni,nj,board,child,ans,vis);
        }
        vis[i][j]=0;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie t;
        for(auto it:words) t.insert(it);
        vector<string> ans;
        int n=board.size(); int m=board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                dfs(i,j,board,t.root,ans,vis);
            }
        }

        return ans;
    }
};