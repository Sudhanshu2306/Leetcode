class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> indegree(n,0);
        for(auto i:roads){
            int u=i[0];
            int v=i[1];
            indegree[u]++; indegree[v]++;
        }

        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            v.push_back({indegree[i],i});
        }
        sort(v.begin(),v.end());
        vector<int> a(n,0);
        for(int i=0;i<n;i++){
            int ind=v[i].second;
            a[ind]=i+1;
        }
        long long ans=0;
        for(auto i:roads){
            ans=ans+a[i[0]]+a[i[1]];
        }
        return ans;
    }
};