class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size(),m=t.size();
        unordered_map<char,int> mp;
        for(int i=0;i<m;i++) mp[t[i]]++;

        int size=1e9; int si=-1;
        int i=0;
        unordered_map<char,int> mpp;
        for(int j=0;j<n;j++){
            mpp[s[j]]++;

            int f=0;
            for(auto it:mp){
                if(mp[it.first]>mpp[it.first]){
                    f=1; break;
                }
            }
            if(!f){
                while(mpp[s[i]]>mp[s[i]]){
                    mpp[s[i]]--;
                    if(mpp[s[i]]==0) mpp.erase(s[i]);
                    i++;
                }

                if(size>j-i+1){
                    size=(j-i+1);
                    si=i;
                }
            }
        }
        if(si!=-1) return s.substr(si,size);
        else return "";
    }
};