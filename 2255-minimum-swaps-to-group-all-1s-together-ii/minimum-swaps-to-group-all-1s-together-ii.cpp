class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int zero=0,one=0;

        int windowsize=0;
        for(int i=0;i<n;i++){
            if(nums[i]==1) windowsize++;
        }
        for(int i=0;i<n;i++){
            nums.push_back(nums[i]);
        }
        int mini=n;
        for(int i=0;i<windowsize;i++){
            if(nums[i]==0) zero++;
            else one++;
            mini=max(mini,windowsize-zero);
        }
        for(int i=1;i<n+n-windowsize+1;i++){
            if(nums[i-1]==0) zero--;
            else one--;
            if(nums[i+windowsize-1]==0) zero++;
            else one++;
            mini=min(mini,zero);
        }
        return mini;
    }
};