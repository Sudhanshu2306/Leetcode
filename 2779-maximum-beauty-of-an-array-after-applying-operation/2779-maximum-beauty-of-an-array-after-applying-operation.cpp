class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        vector<int> temp(3e5+5,0);
        int mini=1e9,maxi=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            temp[nums[i]-k+100000]++;
            temp[nums[i]+k+100001]--;
            maxi=max(maxi,nums[i]-k+100001);
            mini=min(mini,nums[i]-k+100000);
        }
        int x=0; 
        int ans=-1;
        for(int i=mini-1;i<=maxi+1;i++){
            x+=temp[i];
            ans=max(ans,x);
        }
        return ans;
    }
};