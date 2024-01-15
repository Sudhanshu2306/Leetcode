class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        int maxi=0;
        unordered_map<int,vector<int>> mp;
        int n=nums.size();
        for(int i=0;i<n;i++) mp[nums[i]].push_back(i);
        
        for(auto i:mp){
            int size=i.second.size();
            int left=0,right=0;
            while(right<size){
                while(i.second[right]-i.second[left]-(right-left)>k) left++;
                maxi=max(maxi,right-left+1);
                right++;
            }
        }
        return maxi;
    }
};