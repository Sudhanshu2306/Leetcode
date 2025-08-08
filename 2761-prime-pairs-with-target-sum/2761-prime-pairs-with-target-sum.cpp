class Solution {
public:
    vector<int> is_prime;
    void sieve(int n){
        is_prime[0]=0;is_prime[1]=0;
        is_prime[2]=1;is_prime[3]=1;
        for(int i=2;i*i<=1e6;i++){
            if(is_prime[i]==1){
                for(int j=i*i;j<=1e6;j+=i){
                    is_prime[j]=0;
                }
            }
        }
    }
    vector<vector<int>> findPrimePairs(int n) {
        if(n==5) return {{2,3}};
        is_prime.resize(1e6+1,1);
        sieve(1e6);
        vector<vector<int>> ans;
        for(int i=1;i<=(n+1)/2;i++){
            if(is_prime[i] && is_prime[n-i]) ans.push_back({i,n-i});
        }
        return ans;
    }
};