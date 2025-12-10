typedef long long ll;
class Solution {
public:
    int mod=1e9+7;
    int countPermutations(vector<int>& a) {
        int n=a.size();
        if(n==1) return 1;
        for(int i=1;i<n;i++){
            if(a[i]<=a[0]) return 0;
        }
        ll ans=1;
        for(int i=1;i<n;i++){
            ans=(ans*i)%mod;
        }
        return ans;
    }
};