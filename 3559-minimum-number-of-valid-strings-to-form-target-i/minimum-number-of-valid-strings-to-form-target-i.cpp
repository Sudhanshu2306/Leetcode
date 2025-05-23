class Node{
    public:
    vector<Node*> links;
    bool flag;
    Node(){
        links.resize(26,nullptr);
        flag=false;
    }
};
class Trie{
    private:
    public:
    Node* root;
    Trie(){
        root=new Node();
    }
    void insert(string x){
        Node* node=root;
        for(auto it:x){
            if(node->links[it-'a']==nullptr) node->links[it-'a']=new Node();
            node=node->links[it-'a'];
        }
        node->flag=true;
    }
};
class Solution {
public:
    int n; string s; vector<int> dp;
    int solve(int i, Node* root){
        if(i==n) return 0;
        if(dp[i]!=-1) return dp[i];

        int ans=1e9;
        Node* temp=root;
        for(int j=i;j<n;j++){
            if(temp->links[s[j]-'a']==nullptr) break;
            temp=temp->links[s[j]-'a'];
            int x=solve(j+1,root);
            if(x!=1e9) ans=min(ans,x+1);
        }
        return dp[i]=ans;
    }
    int minValidStrings(vector<string>& words, string target) {
        Trie t;
        for(auto it:words) t.insert(it);
        n=target.size();
        s=target; dp=vector<int>(n,-1);
        int ans=solve(0,t.root);

        return ans==1e9?-1:ans;
    }
};