class Node{
    public:
        vector<Node*> links;
        int sum;
    
    Node(){
        links.resize(26);
        for(int i=0;i<26;i++) links[i]=nullptr;
        this->sum=0;
    }
};
class MapSum {
public:
    map<string,int> mp;
    Node* root;
    MapSum() {
        root=new Node();
    }
    
    void insert(string key, int val) {
        Node* curr=root;
        int x=val-mp[key]; mp[key]=val;

        for(auto it:key){
            if(curr->links[it-'a']==nullptr) curr->links[it-'a']=new Node();
            curr=curr->links[it-'a'];
            curr->sum+=x;
        }
    }
    
    int sum(string prefix) {
        Node* curr=root;
        for(auto it:prefix){
            if(curr->links[it-'a']==nullptr) return 0;
            curr=curr->links[it-'a'];
        }
        return curr->sum;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */