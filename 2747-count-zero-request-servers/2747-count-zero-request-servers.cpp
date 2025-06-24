class Solution {
public:
    vector<int> countServers(int z, vector<vector<int>>& logs, int x, vector<int>& q) {
        int n=q.size();
        vector<int> ans(n);
        sort(logs.begin(),logs.end(),[](vector<int> &a, vector<int> &b){
            return a[1]<b[1];
        });
        vector<vector<int>> time(n);
        for(int i=0;i<n;i++) time[i]={q[i],i};
        sort(time.begin(),time.end());

        int i=0,j=0;
        map<int,int> mp;
        for(auto it:time){
            int curr=it[0];
            int ind=it[1];

            int start=max(0,curr-x), end=curr;

            while(j<logs.size() && logs[j][0]<=end){
                mp[logs[j][1]]++; j++;
            }
            while(i<logs.size() && logs[i][1]<start){
                mp[logs[i][1]]--;
                if(mp[logs[i][1]]==0) mp.erase(logs[i][1]);
                i++;
            }
            ans[ind]=z-mp.size();
        }
        return ans;
    }
};