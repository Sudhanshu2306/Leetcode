class Solution {
public:
    int mod=1e9+7;
    vector<vector<long long>> ff(vector<vector<long long>>& a, vector<vector<long long>>& b){
        vector<vector<long long>> ans(26, vector<long long>(26, 0));
        for(int i=0;i<26;i++){
            for(int k=0;k<26;k++){
                if(a[i][k]==0) continue;
                for(int j=0;j<26;j++) ans[i][j]=(ans[i][j]+a[i][k]*b[k][j])%mod;
            }
        }
        return ans;
    }
    
    vector<vector<long long>> pow(vector<vector<long long>> a, int exp) {
        vector<vector<long long>> ans(26, vector<long long>(26, 0));
        for(int i=0;i<26;i++) ans[i][i]=1;
        while(exp>0){
            if(exp%2==1) ans=ff(ans, a);
            a=ff(a,a);
            exp/=2;
        }
        return ans;
    }
    
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        vector<long long> fq(26, 0);
        for(auto ch:s) fq[ch - 'a'] = (fq[ch - 'a'] + 1) % mod;

        vector<vector<long long>> M(26, vector<long long>(26, 0));
        for(int ch=0;ch<26;ch++){
            for(int i=1;i<=nums[ch];i++){
                int j=(ch+i)%26;
                M[ch][j]=(M[ch][j]+1)%mod;
            }
        }
        vector<vector<long long>> Mt = pow(M, t);
        vector<long long> fc(26, 0);
        long long tot=0;
        for(int i=0;i<26;i++){
            if(fq[i]==0) continue;
            for(int j=0;j<26;j++) fc[j]=(fc[j]+fq[i]*Mt[i][j])%mod;
        }
        for(int i=0;i<26;i++) tot=(tot+fc[i]) % mod;
        return static_cast<int>(tot);
    }
};