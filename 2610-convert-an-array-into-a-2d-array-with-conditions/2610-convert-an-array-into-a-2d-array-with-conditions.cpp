class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> mp;
        
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        
        int maxi=0;
        for(auto i:mp){
            maxi=max(maxi,i.second);
        }
        
        vector<vector<int>> res(maxi);
        
        for(auto i:mp){
            int x=i.first;
            int y=i.second;
            for(int j=0;j<y;j++){
                res[j].push_back(x);
            }
        }
        return res;
    }
};