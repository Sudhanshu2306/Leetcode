class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        if(n==1 && nums[0]>=0) return true;
        for(int i=0;i<n-1;i++){
            if(nums[i]==0){
                int j=i-1;
                bool flag=false;
                while(j>=0){
                    if(nums[j]>(i-j)){
                        flag=true;
                        break;
                    }
                    j--;
                }
                if(!flag) return false;
            }
            else{
                i+=nums[i]-1;
            }
        }
        return true;
    }
};