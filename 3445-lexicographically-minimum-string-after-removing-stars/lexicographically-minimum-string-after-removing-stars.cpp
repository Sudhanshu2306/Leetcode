class Solution {
public:
    string clearStars(string s) {
        int n=s.size();
        string ans="";

        auto comp=[](pair<char,int> &a, pair<char,int> &b){
            if(a.first==b.first) return a.second<b.second;
            return a.first>b.first;
        };

        priority_queue<pair<char,int>, vector<pair<char,int>>, decltype(comp)> pq(comp);
        for(int i=0;i<n;i++){
            if(s[i]=='*'){
                if(!pq.empty()) pq.pop();
            }
            else{
                pq.push({s[i],i});
            }
        }
        vector<pair<int,char>> a;
        while(!pq.empty()){
            a.push_back({pq.top().second,pq.top().first});
            pq.pop();
        }
        sort(a.begin(),a.end());
        for(auto it:a) ans+=it.second;

        return ans;
    }
};