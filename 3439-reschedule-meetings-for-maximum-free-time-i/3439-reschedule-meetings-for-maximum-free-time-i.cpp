class Solution {
public:
    int maxFreeTime(int x, int k, vector<int>& s, vector<int>& e) {
        int n=s.size();
        sort(e.begin(),e.end()); sort(s.begin(),s.end());
        vector<int> gap(n+1);
        gap[0]=s[0]; gap[n]=x-e[n-1];

        for(int i=1;i<n;i++) gap[i]=s[i]-e[i-1];

        vector<int> pre(n+2);
        for(int i=1;i<=n+1;i++){
            pre[i]=pre[i-1]+gap[i-1];
        }
        int ans=0;
        for(int i=k+1;i<=n+1;i++){
            ans=max(ans,pre[i]-pre[i-(k+1)]);
        }
        return ans;
    }
};