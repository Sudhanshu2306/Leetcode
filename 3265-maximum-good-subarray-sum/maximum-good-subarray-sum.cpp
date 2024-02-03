class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        vector<long long> prefix(nums.size()); 
        prefix[0]=nums[0];
        for(int i=1; i<nums.size();i++){
            prefix[i]= prefix[i-1]+nums[i];
        }
        
        long long maxi = LONG_MIN;
        bool present = false;
        long long ans;
        
        map<int,vector<int>> arr;
        
        for(int i=0;i< nums.size();i++){
            if(arr.find(nums[i]+k)!=arr.end()){
                present=true;
                for(auto x:arr[nums[i]+k]){
                    if(x==0)ans = prefix[i];
                    else ans = prefix[i]-prefix[x-1];
                    maxi = max(maxi,ans);
                }
            }
            if(arr.find(nums[i]-k)!=arr.end()){
                present=true;
                for(auto x:arr[nums[i]-k]){
                    if(x==0) ans=prefix[i];
                    else ans= prefix[i]-prefix[x-1];
                    maxi = max(maxi,ans);
                }
            }
            
            arr[nums[i]].push_back(i);
        }
        
        if(present) return maxi;
        else return 0;
    }
};