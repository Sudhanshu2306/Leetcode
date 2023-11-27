class Solution {
public:
    int knightDialer(int n) {
        int mod=1e9+7;
        if(n==1){
            return 10;
        }
        unordered_map<int,vector<int>> mp;
        mp[1]={6,8}; mp[2]={7,9};mp[3]={4,8};mp[4]={0,3,9};mp[5]={};
        mp[6]={0,1,7}; mp[7]={2,6};mp[8]={1,3};mp[9]={2,4};mp[0]={4,6};
        
        vector<int> v(10,1);
        for(int i=2;i<=n;i++){
            vector<int> temp(10);
            for(auto k:mp){
                for(auto j:k.second){
                    temp[k.first]=(temp[k.first]+v[j])%mod;
                }
            }
            v=temp;
        }
        long long ans=0;
        for(int i=0;i<10;i++){
            ans=(ans+v[i])%mod;
        }
        return ans;
    }
};