class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        int mp[32]={0};
        int n=nums.size();
        for(int k=0;k<n;k++){
            int ind=1;
            while(nums[k]){
                mp[32-ind++]+=nums[k]&1;
                nums[k]>>=1;
            }
        }
        int ans=0;
        for(auto i:mp){
            ans=ans*2+(i>=k);
        }
        return ans;
    }
};