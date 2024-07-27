#define ll long long
class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<ll>> dist(26,vector<ll>(26,1e9));

        for(int i=0;i<original.size();i++){
            char u=original[i];
            char v=changed[i];
            ll wt=cost[i];
            dist[u-'a'][v-'a']=min(dist[u-'a'][v-'a'],wt);
        }

        for(int i=0;i<26;i++) dist[i][i]=0;
        for(int k=0;k<26;k++){
            for(int i=0;i<26;i++){
                for(int j=0;j<26;j++){
                    if(i==j) continue;
                    if(dist[i][k]==1e9 || dist[k][j]==1e9) continue;
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
        ll ans=0;
        for(int i=0;i<target.size();i++){
            if(source[i]!=target[i]){
                if(dist[source[i]-'a'][target[i]-'a']==1e9) return -1;
                ans+=dist[source[i]-'a'][target[i]-'a'];
            }
        }
        return ans;
    }
};