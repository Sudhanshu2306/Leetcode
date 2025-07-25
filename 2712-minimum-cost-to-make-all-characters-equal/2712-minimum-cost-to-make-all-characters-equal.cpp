typedef long long ll;
class Solution {
public:
    long long minimumCost(string s) {
        int n=s.size();
        ll mini=1e18;
        vector<ll> pre(n,0), suf(n,0);
        for(int i=1;i<n;i++){
            if(s[i]!=s[i-1]) pre[i]+=(pre[i-1]+i);
            else pre[i]=pre[i-1];
        }
        for(int i=n-2;i>=0;i--){
            if(s[i]!=s[i+1]) suf[i]+=(suf[i+1]+n-i-1);
            else suf[i]=suf[i+1];
        }
        for(int i=0;i<n;i++) mini=min(mini,suf[i]+pre[i]);
        return mini;
    }
};