class Solution {
public:
    int f(int n){
        int sum=0;
        while(n){
            sum+=(n%10); n/=10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        vector<int> a;
        for(auto it:nums){
            a.push_back(f(it));
        }
        map<int,vector<int>> mp;
        for(int i=0;i<nums.size();i++){
            mp[a[i]].push_back(nums[i]);
        }
        int maxi=-1e9;
        for(auto it:mp){
            vector<int> x=it.second;
            sort(x.begin(),x.end());
            if(x.size()>=2){
                maxi=max(maxi,x.back()+x[x.size()-2]);
            }
        }
        return maxi==-1e9?-1:maxi;
    }
};