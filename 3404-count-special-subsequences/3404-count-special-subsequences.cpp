class Solution {
public:
    long long numberOfSubsequences(vector<int>& nums) {
        map<double,long long> mp;
        int n=nums.size();
        long long count=0;
        for(int i=4;i<n;i++){
            int k=i-2;
            for(int j=0;j<k-1;j++){
                mp[(double)nums[j]/(double)nums[k]]++;
            }
            for(int l=i+2;l<n;l++) count+=mp[(double)nums[l]/(double)nums[i]];
        }
        return count;
    }
};