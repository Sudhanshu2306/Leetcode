class Solution {
public:
    // most classical varialble size sliding window question
    string minWindow(string s, string t) {
        unordered_map<char,int> mp;
        
        for(int i=0;i<t.length();i++){
            mp[t[i]]++;
        }
        int count=mp.size();
        string ans="";
        int mini=INT_MAX;
        int i=0,j=0;
        int st=0;
        while(j<s.length()){
            // if(mp.find(s[j])==mp.end()) j++;
            if(mp.find(s[j])!=mp.end()){
                mp[s[j]]--;
                if(mp[s[j]]==0) count--;
            }
            if(count==0){
                while(count==0){
                    if(mp.find(s[i])!=mp.end()){
                        mp[s[i]]++;
                        if(mp[s[i]]==1){
                            count++;
                            if((j-i+1)<mini){
                                mini=(j-i+1);
                                st=i;
                            }
                        }
                    }
                    i++;
                }
            }
            j++;
        }
        if(mini==INT_MAX) return "";
        else return s.substr(st,mini);
    }
};