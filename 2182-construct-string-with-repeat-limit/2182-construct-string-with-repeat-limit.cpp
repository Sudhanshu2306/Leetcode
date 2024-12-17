class Solution {
public:
    string repeatLimitedString(string s, int z){
        int n=s.size();
        string ans="";
        map<int,int> mp;
        for(int i=0;i<n;i++) mp[s[i]]++;
        priority_queue<pair<int,char>> pq;
        for(auto it:mp) pq.push({it.first,it.second});

        while(!pq.empty()){
            int count=0;
            auto x=pq.top(); pq.pop();
            int y=x.second; char ch=x.first;
            
            if(!ans.empty() && ans.back()==ch){
                if(pq.empty()) return ans;
                else{
                    auto temp=pq.top(); pq.pop();
                    ans+=string(1,temp.first);
                    if(temp.second-1>0) pq.push({temp.first,temp.second-1});
                }
            }
            if(y<=z) ans+=string(y,ch);
            else{
                ans+=string(z,ch); y-=z;
                pq.push({ch,y});
            }
        }
        return ans;
    }
};