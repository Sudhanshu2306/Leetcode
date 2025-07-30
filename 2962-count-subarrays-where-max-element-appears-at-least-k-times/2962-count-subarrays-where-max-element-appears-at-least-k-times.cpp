typedef long long ll;
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        ll n=nums.size();
        ll maxi=*max_element(nums.begin(),nums.end());
        ll count=0;
        ll i=0,j=0;
        ll len=0;
        while(j<n){
            if(nums[j]==maxi) len++;
            if(len>=k){
                count+=(n-1-j)+1;
                while(len>=k && i<=j){
                    if(nums[i]==maxi) len--;
                    i++;
                    if(len>=k) count+=(n-j-1)+1;
                }
            }
            j++;
        }
        return count;
    }
};