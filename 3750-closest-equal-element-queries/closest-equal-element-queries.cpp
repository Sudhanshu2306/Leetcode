class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        // for(int i=0;i<z;i++) nums.push_back(nums[i]);
        map<int,vector<int>> mp;
        int n=nums.size();
        for(int i=0;i<n;i++) mp[nums[i]].push_back(i);
        for(auto &it:mp){
            sort(it.second.begin(), it.second.end());
        }

        auto f=[&](int i, int j){
            int diff=abs(i-j);
            return min(diff, n-diff);
        };
        vector<int> ans(queries.size(),-1);
        for(int k=0;k<queries.size();k++){
            int val=nums[queries[k]];
            auto &x=mp[val];

            if(x.size()<2) continue;

            auto y=lower_bound(x.begin(),x.end(),queries[k]);
            int z=x.size();
            int rightIndex=(y-x.begin())%z;
            int leftIndex=(rightIndex-1+z)%z;
            
            int leftPos=x[leftIndex];
            int rightPos=x[rightIndex];

            if(x[rightIndex]==queries[k]) rightPos=x[(rightIndex+1)%z];
            if(leftPos==queries[k]) leftPos=x[(leftIndex-1+z)%z];

            ans[k]=min(f(queries[k],leftPos), f(queries[k],rightPos));
        }
        return ans;
    }
};