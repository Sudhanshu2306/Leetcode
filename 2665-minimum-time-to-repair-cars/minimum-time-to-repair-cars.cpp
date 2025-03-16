typedef long long ll;
class Solution {
public:
    bool f(ll mid, vector<int> &a, int k){
        ll count=0;
        for(auto it:a) count+=sqrtl(mid/it);

        return count>=k;
    }
    // bs on answers
    long long repairCars(vector<int>& ranks, int cars) {
        sort(ranks.begin(), ranks.end());
        ll s=0,e=1e15;

        while(s<=e){
            ll mid=s+(e-s)/2;
            if(f(mid,ranks,cars)) e=mid-1;
            else s=mid+1;
        }
        return s;
    }
};