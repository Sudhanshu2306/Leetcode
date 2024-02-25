class Graph{
    public:
        int n; 
        vector<vector<int>> edges;

        void traverse(int x, vector<bool> &vis){
            vis[x]=true;
            for(auto y:edges[x]){
                if(!vis[y]) traverse(y,vis);
            }
        }

        Graph(int n=0):n(n) {
            edges.resize(n);
        }

        void addEdge(int x,int y){
            edges[x].push_back(y);
            edges[y].push_back(x);
        }

        bool isConnected(){
            vector<bool> vis(n);
            traverse(0,vis);
            return count(vis.begin(),vis.end(),true)==n;
        }
};

class Solution {
    public:
    vector<int> primes(int x){
        vector<int> ans;
        for(int i=2;i*i<=x;i++){
            if(x%i==0){
                ans.push_back(i);
                while(x%i==0){
                    x/=i;
                }
            }
        }
        if(x!=1) ans.push_back(x);

        return ans;
    }

public:
    bool canTraverseAllPairs(vector<int>& nums) {
        unordered_map<int,int> mp;
        
        int n=nums.size();
        if(n==1) return true;

        Graph g(n);

        for(int i=0;i<n;i++){
            if(nums[i]==1){
                return false;
            }
            vector<int> prime=primes(nums[i]);
            for(auto x:prime){
                if(mp.find(x)!=mp.end()){
                    g.addEdge(i,mp[x]);
                }
                else{
                    mp[x]=i;
                }
            }
        }
        return g.isConnected();
    }
};