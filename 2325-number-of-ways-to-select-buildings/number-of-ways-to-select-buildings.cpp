class Solution {
public:
    long long numberOfWays(string s) {
        // dp state socho?
        // par better h ki 0 01 aur 010 socho
        // similarly 1 10 101 socho
        int n=s.size();
        vector<long long> p1(n), p0(n);
        p0[0]=(s[0]=='0'?1:0);
        p1[0]=(s[0]=='1'?1:0);

        for(int i=1;i<n;i++){
            if(s[i]=='1') {
                p1[i]=1+p1[i-1];
                p0[i]=p0[i-1];
            }

            if(s[i]=='0') {
                p0[i]=1+p0[i-1];
                p1[i]=p1[i-1];
            }
        }
        vector<long long> p10(n,0), p01(n,0);

        for(int i=1;i<n;i++){
            if(s[i]=='0') {
                p01[i]=p01[i-1];
                p10[i]=p10[i-1]+p1[i-1];
            }

            if(s[i]=='1') {
                p10[i]=p10[i-1];
                p01[i]=p01[i-1]+p0[i-1];
            }
        }

        long long ans=0;
        for(int i=n-1;i>=2;i--){
            if(s[i]=='0') ans+=p01[i-1];
            else ans+=p10[i-1];
        }
        return ans;
    }
};