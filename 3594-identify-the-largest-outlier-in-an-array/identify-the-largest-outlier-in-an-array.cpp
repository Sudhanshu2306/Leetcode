class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        map<int,int> mp;
        int maxi=-1e9;

        int sum=accumulate(nums.begin(),nums.end(),0);
        for(auto it:nums) mp[it]++;

        for(auto it:nums){
            sum-=it; mp[it]--;
            if(mp[it]==0) mp.erase(it);
            if(sum%2==0 && mp.find(sum/2)!=mp.end()) maxi=max(maxi,it);
            sum+=it; mp[it]++;
        }
        return maxi;
    }
};