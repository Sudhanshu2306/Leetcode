class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        set<int> st,x;
        vector<int> in(n,0);
        vector<vector<int>> adj(n);
        for(auto it:edges){
            in[it[1]]++;
            adj[it[0]].push_back(it[1]);
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(in[i]==0){
                q.push(i); x.insert(i);
            } 
        }
        while(!q.empty()){
            auto it=q.front(); q.pop();
            st.insert(it);
            for(auto i:adj[it]){
                in[i]--;
                if(in[i]==0) q.push(i);
            }
        }
        for(int i=0;i<n;i++){
            if(st.find(i)==st.end()) x.insert(i);
        }
        vector<int> ans(x.begin(),x.end());
        return ans;
    }
};