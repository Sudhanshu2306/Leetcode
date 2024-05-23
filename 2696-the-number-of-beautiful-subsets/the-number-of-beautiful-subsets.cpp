class Solution {
public:
    void f(vector<int>& nums, unordered_map<int,int>& mp, vector<int>& ans, int ind,int k){
        if(ind<0)return;

        for(int i=ind;i>=0;i--){
            if(!mp.empty() && mp.count(nums[i]) && mp[nums[i]]>0) continue;
            ans.push_back(nums[i]);
            int temp=nums[i]-k;
            mp[temp]++;
            count++;
            f(nums,mp,ans,i-1,k);
            ans.pop_back();
            mp[temp]--;
        }
    }
    int count=0;
    int beautifulSubsets(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        unordered_map<int,int> mp;
        vector<int> ans;
        

        f(nums,mp,ans,n-1,k);
        return count;
    }
};