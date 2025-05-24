class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n=s.size();
        vector<int> ans;
        map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[s[i]]=i;
        }
        int maxi=0, prev=-1;
        for(int i=0;i<n;i++){
            maxi=max(maxi,mp[s[i]]);
            if(maxi==i){
                ans.push_back(maxi-prev);
                prev=maxi;
            }
        }
        return ans;
    }
};