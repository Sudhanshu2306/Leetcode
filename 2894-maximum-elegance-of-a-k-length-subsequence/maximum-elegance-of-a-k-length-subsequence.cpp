typedef long long ll;
class Solution {
public:
    long long findMaximumElegance(vector<vector<int>>& items, int k) {
        sort(items.rbegin(),items.rend());
        ll ans=0, sum=0;
        set<ll> st;
        vector<ll> x;
        for(int i=0;i<items.size();i++){
            if(i<k){
                if(st.find(items[i][1])!=st.end()) x.push_back(items[i][0]);
                sum+=items[i][0];
            }
            else if(st.find(items[i][1])==st.end()){
                if(x.size()==0) break;
                else{
                    sum+=items[i][0];
                    sum-=x.back();
                    x.pop_back();
                }
            }
            st.insert(items[i][1]);
            ll z=sum+1LL*st.size()*st.size();
            ans=max(ans,z);
        }
        return ans;
    }
};