class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        while(!is_sorted(nums.begin(),nums.end())){
            int ind=0;
            int mini=nums[0]+nums[1];
            for(int i=1;i<nums.size()-1;i++){
                int sum=nums[i]+nums[i+1];
                if(sum<mini){
                    mini=sum; ind=i;
                }
            }
            nums[ind]=mini;
            nums.erase(nums.begin()+ind+1);
            ans++;
        }
        return ans;
    }
};