class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();

        // Initialize variables to keep track of maximum and second maximum values.
        long long maxitrip = LLONG_MIN;
        for (int i = 0; i < n-2; i++) {
            for(int j =i+1;j <n-1;j++){
                for(int k=j+1;k<n;k++){
                    long long maxi = static_cast<long long>(nums[i] - nums[j]) * nums[k];
                    if(maxi>maxitrip){
                        maxitrip=maxi;
                    }
                }
            }
        }
        return maxitrip > 0 ? maxitrip : 0;
    }
};