class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        vector<int> z=nums;
        sort(z.begin(),z.end());
        if(z==nums) return true;
        
        map<int,vector<int>> mp;
        for(auto it:nums){
            int x=__builtin_popcount(it);
            mp[x].push_back(it);
        }
        vector<vector<int>> temp;
        for(auto it:mp){
            sort(it.second.begin(),it.second.end());
            temp.push_back(it.second);
        }
        for(int i=0;i<temp.size()-1;i++){
            if(temp[i].back()>temp[i+1][0]) return false;
        }
        return true;
    }
};