class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int,int> mp;
        int x=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            x^=nums[i];
            mp[nums[i]]++;
        }
        int y;
        for(auto i:mp){
            if(i.second==1){
                y=i.first;
                break;
            } 
        }
        return {x^y,y};
    }
};