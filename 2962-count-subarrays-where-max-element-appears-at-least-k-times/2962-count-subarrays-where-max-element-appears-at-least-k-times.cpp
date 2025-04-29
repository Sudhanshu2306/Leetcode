class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long count=0;
        int n=nums.size();

        int i=0,j=0;
        long long maxi=*max_element(nums.begin(),nums.end());
        long long temp=0;
        while(j<n){
            if(nums[j]==maxi) temp++;
            if(temp>=k){
                count+=((n-1-j)+1);
                while(i<=j && temp>=k){
                    if(nums[i]==maxi) temp--;

                    if(temp>=k) count+=((n-1-j)+1);
                    i++;
                }
            }
            j++;
        }
        return count;
    }
};