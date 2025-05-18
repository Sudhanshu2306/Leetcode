class Solution {
public:
    vector<vector<long long int>> dp;
    vector<string> v;
    int mod=1e9+7;
    
    void recurs(int m,char prev,string s){
        if(m==0){
            v.push_back(s); return;
        }
        string c="RGB";
        
        for(auto x:c){
            if(x!=prev) recurs(m-1,x,s+x);
        }
    }
    
    
    long long recurs(vector<int>graph[], int i,int n){
        if(n==1) return 1;
        
        if(dp[i][n]!=-1) return dp[i][n];
        
        long long a=0;
        
        for(auto x:graph[i])
            a+=recurs(graph,x,n-1)%mod;
        
        return dp[i][n]=a%mod;
    }
    
    int colorTheGrid(int m, int n){
        recurs(m,'*',"");
        vector<int>graph[v.size()];
        
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v.size();j++){
                bool flag=1;
                for(int k=0;k<m;k++){
                    if(v[i][k]==v[j][k]){
                        flag=0;
                        break;
                    }
                }
                if(flag&&i!=j) graph[i].push_back(j);
            }
        }
        
        long long ans=0;
        dp.resize(v.size(),vector<long long>(n+1,-1));
        
        for(int i=0;i<v.size();i++)
            ans+=recurs(graph,i,n)%mod;

        return ans%mod;
    }
};