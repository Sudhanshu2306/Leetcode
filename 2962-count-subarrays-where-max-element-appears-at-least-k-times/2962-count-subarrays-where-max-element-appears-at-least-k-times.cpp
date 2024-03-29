class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int x=*max_element(nums.begin(),nums.end());
        // return x;
        int count=0;
        int i=0,j=0;
        int ans=0;
        int n=nums.size();
        while(j<n){
            if(nums[j]==x){
                count++;
            } 
            if(count>=k){
                ans+=(n-j);  // why?? kyuki bhai aage ke saare elements ko add karenge phir bhi valid hoga
                while(i<=j && count>=k){
                    if(nums[i]==x) count--;
                    if(count>=k) ans+=(n-j);
                    i++;
                }
            }
            j++;
        }
        return ans;
    }
};