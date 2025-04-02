class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        // Initialize variables to keep track of maximum and second maximum values.
        long long maxi=LLONG_MIN;
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                for(int k=j+1;k<n;k++){
                    long long z=((nums[i]-nums[j])*1LL*nums[k]);
                    if(z>maxi){
                        maxi=z;
                    }
                }
            }
        }
        return maxi>0?maxi:0;
    }
};