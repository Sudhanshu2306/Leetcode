class Solution {
public:
    void f(vector<int>& nums, map<int,int>& mp, int ind,int k){
        if(ind<0) return;

        for(int i=ind;i>=0;i--){
            if(!mp.empty() && mp.find(nums[i])!=mp.end()) continue;
            int temp=nums[i]-k;
            mp[temp]++;
            count++;
            f(nums,mp,i-1,k);
            mp[temp]--;
            if(mp[temp]==0) mp.erase(temp);
        }
    }
    int count=0;
    int beautifulSubsets(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        map<int,int> mp;
        
        f(nums,mp,n-1,k);
        return count;
    }
};