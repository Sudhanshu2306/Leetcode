using ll=long long;
class Solution {
public:
    bool f(vector<int>& a, int d, ll maxi) {
        ll last=a[0];
        for(int i=1;i<a.size();i++){
            if(last+maxi>a[i]+d) return false;
            else last=max(last+maxi,(ll)a[i]);
        }
        return true;
    }
    
    int maxPossibleScore(vector<int>& a, int d) {
        sort(a.begin(), a.end());
        int n=a.size();
        ll s=0, e=(ll)d+a[n-1]-a[0];
        ll result=0;
        while (s<=e) {
            ll mid=s+(e-s)/2;
            if(f(a,d,mid)) {
                result=mid;
                s=mid+1;
            } 
            else e=mid-1;
        }
        
        return (int)result;
    }
};