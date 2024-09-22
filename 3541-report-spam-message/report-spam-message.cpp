class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        unordered_map<string,int> mp;
        set<string> st;
        for(auto i:bannedWords){
            st.insert(i);
        }
        for(auto i:st){
            mp[i]++;
        }
        int count=0;
        for(auto i:message){
            if(mp.find(i)!=mp.end()){
                count+=mp[i];
                if(count>=2) return true;
            }
        }
        
        return false;
    }
};