class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]].push_back(i);
        }

        int mini=1e9;
        // circular index;
        for(auto &i:mp){
            vector<int> x=i.second;
            x.push_back(x[0]+nums.size());
            mp[i.first]=x;
        }
        // (i+1)->(j-1) 
        for(auto &i:mp){
            int num=i.first;
            vector<int> ind=i.second;
            int diff=0;
            for(int j=0;j<ind.size()-1;j++){
                diff=max(diff,(ind[j+1]-ind[j])/2);
            }
            mini=min(mini,diff);
        }
        return mini;
    }
};