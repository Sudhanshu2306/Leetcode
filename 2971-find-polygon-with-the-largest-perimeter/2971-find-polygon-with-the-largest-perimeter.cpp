class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        long long sum=nums[0];
        for(int i=1;i<n;i++){
            sum+=nums[i];
        }
        int i=n-1;
        long long x=nums[i];
        while(i>0 && nums[i]>=sum-x){
            x+=nums[i-1];
            i--; 
        }
        x-=nums[i];
        if(i==0) return -1;
        else return sum-x;
    }
};