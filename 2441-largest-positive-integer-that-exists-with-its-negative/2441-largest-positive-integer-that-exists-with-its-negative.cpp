class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i:nums){
            mp[i]=1;
        }
        int maxi=-1;
        for(int i:nums){
            if(i>0 && mp[i] && mp[0-i]) maxi=max(maxi,i);
        }
        return maxi;
    }
};