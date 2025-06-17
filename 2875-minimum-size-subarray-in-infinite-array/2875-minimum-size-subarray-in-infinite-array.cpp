class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
        long long sum=accumulate(nums.begin(),nums.end(),0LL);
        int n=nums.size();
        long long rem=target%sum;
        long long quo=target/sum;
        if(rem==0){
            return quo*n;
        }
        vector<int> temp; 
        for(int i=0;i<n;i++) temp.push_back(nums[i]);
        for(int i=0;i<n;i++) temp.push_back(nums[i]);

        int i=0,j=0;
        int x=0;
        int mini=1e9;
        
        while(j<temp.size()){
            x+=temp[j];
            while(x>rem && i<j){
                x-=temp[i];
                i++;
            }
            if(x==rem) mini=min(mini,j-i+1);
            j++;
        }
        return mini==1e9?-1:mini+quo*n;
    }
};