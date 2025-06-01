class Solution {
public:
    long long distributeCandies(int n, int limit) {
        int count=0;
        for(int i=0;i<=limit;i++){
            int remaining_candies=n-i;

            int max_num_of_candies=min(remaining_candies,limit);
            int min_num_of_candies=max(remaining_candies-limit,0);

            count+=max(max_num_of_candies-min_num_of_candies+1,0);
        }
        return count;
    }
};