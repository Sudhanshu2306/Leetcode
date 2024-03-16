class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        int maxi=0;
        int sum=0;

        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            if(nums[i]!=0) sum+=1;
            else sum-=1;
            
            if(sum==0) maxi=i+1;
            if(mp.find(sum)!=mp.end()) maxi=max(maxi,i-mp[sum]);
            else mp[sum]=i;
        }        
        return maxi;
    }
};