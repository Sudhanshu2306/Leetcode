class Solution {
public:
    int earliestFinishTime(vector<int>& lst, vector<int>& ld, vector<int>& wst, vector<int>& wd) {
        vector<pair<int,int>> a,b;
        int mini=1e9;
        for(int i=0;i<lst.size();i++){
            mini=min(mini,lst[i]+ld[i]);
        }
        int ans=1e9;

        for(int i=0;i<wst.size();i++){
            ans=min(ans,wd[i]+max(mini,wst[i]));
        }
        mini=1e9;
        for(int i=0;i<wst.size();i++){
            mini=min(mini,wst[i]+wd[i]);
        }

        for(int i=0;i<lst.size();i++){
            ans=min(ans,ld[i]+max(mini,lst[i]));
        }
        return ans;
        
    }
};