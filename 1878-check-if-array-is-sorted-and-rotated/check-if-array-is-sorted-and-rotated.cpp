class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        int i;
        for(i=1;i<n;i++){
            if(nums[i]>=nums[i-1]){

            }
            else break;
        }
        // cout<<i;
        if(i==n) return true;
        else{
            for(int j=i+1;j<n;j++){
                if(nums[j]>=nums[j-1]){

                }
                else return false;
            }
            if(nums[0]>=nums[n-1]) return true;
            else return false;
        }
    }
};