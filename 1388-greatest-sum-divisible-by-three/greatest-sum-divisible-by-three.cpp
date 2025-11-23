class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        long long sum = accumulate(nums.begin(), nums.end(), 0LL);
        int rem = sum % 3;
        sort(nums.begin(), nums.end());

        if (rem == 0) return sum;

        if (rem == 1) {
            long long x = 0;   
            int count = 0;
            long long y = 1e18;

            for (auto it : nums) {
                if (it % 3 == 2 && count < 2) {
                    x += it; 
                    count++;
                }
                else if (it % 3 == 1 && y == 1e18) {
                    y = it;
                }
            }

            long long ans = 0;
            long long op1 = (y != 1e18 ? sum - y : 0);       
            long long op2 = (count == 2 ? sum - x : 0);         

            ans = max(op1, op2);
            return ans;
        } 
        else {

            long long x = 0;     
            int count = 0;
            long long y = 1e18;  

            for (auto it : nums) {
                if (it % 3 == 1 && count < 2) {
                    x += it;
                    count++;
                }
                else if (it % 3 == 2 && y == 1e18) {
                    y = it;
                }
            }

            long long ans = 0;
            long long op1 = (y != 1e18 ? sum - y : 0);   
            long long op2 = (count == 2 ? sum - x : 0);          

            ans = max(op1, op2);
            return ans;
        }
    }
};
