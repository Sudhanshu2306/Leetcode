class Solution {
public:
    long long maxScore(vector<int>& nums) {
        int n=nums.size();
        int ans1=nums[0];
        for(int j=1;j<nums.size();j++){
            ans1=__gcd(ans1,nums[j]);
        }
        int ans2=nums[0];
        for(int j=1;j<nums.size();j++){
            ans2=(ans2/__gcd(ans2,nums[j]))*nums[j];
        }
        long long maxi=(long long)ans1*(long long)ans2;
        // long long maxi=-1e18;
        for(int i=0;i<n;i++){
            vector<int> temp(nums.begin(),nums.end());
            temp.erase(temp.begin()+i);

            int ans1=temp[0];
            for(int j=1;j<temp.size();j++){
                ans1=__gcd(ans1,temp[j]);
            }
            int ans2=temp[0];
            for(int j=1;j<temp.size();j++){
                ans2=(ans2/__gcd(ans2,temp[j]))*temp[j];
            }

            long long ans=(long long)ans1*(long long)ans2;
            maxi=max(maxi,ans);
        }
        return maxi;
    }
};