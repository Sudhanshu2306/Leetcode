class Solution {
public:
    int minAnagramLength(string s) {
        map<char,int> mp;
        for(char c:s) mp[c]++;

        int g=0;
        for(auto it:mp) g=__gcd(g,it.second);

        int n=s.size();
        for(int k=(n/g);k<=n;k+=(n/g)){
            if(n%k!=0) continue;

            vector<int> f(26,0);
            for(int i=0;i<k;i++) f[s[i]-'a']++;

            bool flag=true;
            for(int i=k;i<n;i+=k){
                vector<int> cnt(26,0);
                for(int j=0;j<k;j++) cnt[s[i+j]-'a']++;
                if(cnt!=f){ flag = false; break; }
            }

            if(flag) return k;
        }
        return n; 
    }
};
