class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int n=nums.size();
        map<int,int> mp;
        vector<int> ans;
        int i=0;int j=0;
        while(j<n){
            if(nums[j]<0){
                mp[nums[j]]++;
            }
            if(j-i+1<k){
                j++;
            }
            else if(j-i+1==k){
                int count=0;
                for(auto itr:mp){
                    count+=itr.second;
                    if(count>=x){
                        ans.push_back(itr.first);
                        break;
                    } 
                }
                if(count<x) ans.push_back(0);
                if(mp.find(nums[i])!=mp.end()){
                    mp[nums[i]]--;
                    if(mp[nums[i]]==0) mp.erase(nums[i]);
                }
                i++;j++;
            }
        }
        return ans;
    }
};