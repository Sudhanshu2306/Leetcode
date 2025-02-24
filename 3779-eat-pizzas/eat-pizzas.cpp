class Solution {
public:
    long long maxWeight(vector<int>& a) {
        sort(a.begin(),a.end(), greater<int>());
        int n=a.size();
        int sets=n/4; int odd=(sets+1)/2;
        int i=0;
        long long ans=0;
        for(int x=1;x<=sets;x++){
            if(x>odd) i++;
            ans+=(long long) a[i];
            i++;
        }
        return ans;
    }
};