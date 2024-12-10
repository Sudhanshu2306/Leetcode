class Solution {
public:
    int maximumLength(string s) {
        unordered_map<string,int> mp;
        int n=s.length();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                string x = s.substr(i,j-i+1);
                if(x==string(j-i+1,s[i]))
                    mp[x]++;
            }
        }
        long long ans=-1;
        for(auto i:mp){
            if(i.second>2){
                ans=max(ans,static_cast<long long>(i.first.size()));
            }
        }
        return ans;
    }
};