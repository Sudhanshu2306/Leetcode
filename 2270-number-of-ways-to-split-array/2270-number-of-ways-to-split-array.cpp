class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n=nums.size();
        vector<double> pre(n);
        pre[0]=nums[0];
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]+nums[i];
        }
        double count=0;
        for(int i=0;i<n-1;i++){
            if(pre[i]>=(pre[n-1]-pre[i])) count++;
        }
        return (int)count;
    }
};