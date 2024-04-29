class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans=0;
        for(int i:nums) ans^=i;
        int c=0;
        ans^=k;
        while(ans>0){
            c+=(ans&1);
            ans=ans>>1;
        }
        return c;
    }
};