class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int i=0,j=0, set_bits=0;
        int n=nums.size();
        int maxi=1;
        while(j<n){
            while(i<=j && (set_bits&nums[j])!=0){
                set_bits^=nums[i]; i++;
            }
            set_bits|=nums[j];
            maxi=max(maxi,j-i+1);
            j++;
        }
        return maxi;
    }
};