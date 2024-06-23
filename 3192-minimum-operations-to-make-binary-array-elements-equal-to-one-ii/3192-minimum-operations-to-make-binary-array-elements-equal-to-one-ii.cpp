class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int flag=0;
        int ans=0;
        

        for(int i=0;i<n; i++) {
            if(flag){
               if(nums[i]==1){
                   flag=0;
                   ans++;
                   // cout<<ans<<" ";
               } 
            }
            else{
                if(nums[i]==0){
                    flag=1;
                    ans++;
                    // cout<<ans<<" ";
                }
            }
        }
        return ans;
    }
};