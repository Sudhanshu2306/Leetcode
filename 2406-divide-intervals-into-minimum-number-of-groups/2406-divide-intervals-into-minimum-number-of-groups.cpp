class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<int> a(1e5,0);
        for(auto it:intervals){
            int l=it[0]; int r=it[1];
            a[l-1]++, a[r]--;
        }
        for(int i=1;i<intervals.size();i++){
            a[i]+=a[i-1];
        }
        int ans=*max_element(a.begin(),a.end());
        return ans;
    }
};