class Solution {
public:
    int numberOfArrays(vector<int>& a, int lower, int upper) {
        long long x=0;
        long long maxi=0,mini=0;
        for(auto it:a){
            x+=it;
            maxi=max(maxi,x);
            mini=min(mini,x);
        }
        return max(0LL,mini-maxi+upper-lower+1);
    }
};