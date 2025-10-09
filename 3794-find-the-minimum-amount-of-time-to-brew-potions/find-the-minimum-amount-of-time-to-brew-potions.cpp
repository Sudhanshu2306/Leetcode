class Solution {
public:
    typedef long long ll;
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n=skill.size();
        int m=mana.size();
        vector<ll> ans(n+1);

        for(int j=0;j<m;j++){
            for(int i=0;i<n;i++){
                ans[i+1]=max(ans[i],ans[i+1])+skill[i]*mana[j];
            }
            for(int i=n-1;i>=0;i--){
                ans[i]=ans[i+1]-skill[i]*mana[j];
            }
        }
        return ans[n];
    }
};