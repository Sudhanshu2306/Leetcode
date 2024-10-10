class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int maxi=0;
        vector<pair<int,int>> a;
        for(int i=0;i<nums.size();i++){
            a.push_back({nums[i],i});
        }
        sort(a.begin(),a.end());
        int ind=a[0].second;

        for(auto it:a){
            maxi=max(maxi,it.second-ind);
            ind=min(ind,it.second);
        }
        return maxi;
    }
};