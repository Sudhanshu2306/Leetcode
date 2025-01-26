class Solution {
public:
    vector<int> countMentions(int n, vector<vector<string>>& events) {
        vector<int> ans(n,0);
        map<int,vector<pair<int,int>>> mp; 
    
        sort(events.begin(),events.end(), [](auto& a, auto& b) {
            return stoi(a[1])<stoi(b[1]);
        });
    
        for(auto& it:events){
            int t=stoi(it[1]);
            if(it[0]=="OFFLINE"){
                int userId=stoi(it[2]);
                mp[t].push_back({userId,t+60});
            }
        }
        for(auto& it:events){
            int t=stoi(it[1]);
            if(it[0]=="MESSAGE"){
                string s=it[2];
    
                vector<pair<int, int>> curr;
                for(auto &it:mp) {
                    if(it.first <= t){
                        for(const auto& user:it.second) curr.push_back(user);
                    }
                }
                curr.erase(remove_if(curr.begin(), curr.end(),
                                            [&](const auto& p){ return p.second <= t; }),curr.end());
    
                unordered_set<int> st;
                for(int i=0;i<n;i++){
                    bool flag = false;
                    for(const auto& it:curr){
                        if(it.first==i){
                            flag=true; break;
                        }
                    }
                    if(!flag) st.insert(i);
                }
                if(s=="ALL"){
                    for(int i=0;i<n;i++) ans[i]++;
                } 
                else if(s=="HERE"){
                    for(int it:st) ans[it]++;
                } 
                else{
                    stringstream ss(s);
                    string token;
                    while(ss>>token){
                        if(token.substr(0,2)=="id"){
                            int userId = stoi(token.substr(2));
                            ans[userId]++;
                            
                        }
                    }
                }
            }
        }
    
        return ans;
    }
};