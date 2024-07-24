class Solution {
public:
    long long distributeCandies(int n, int limit) {
        // 1st bande ka i se number of candies cover hoga
        long long ans=0;
        for(int i=0;i<=limit;i++){
            int rem=n-i;
            int max_of_second=min(rem,limit);
            int min_of_second=max(rem-limit,0);
            int z=max(max_of_second-min_of_second+1,0);
            ans+=z;
        }
        return ans;
    }
};