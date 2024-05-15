class Solution {
    bool isPrime(int n){
        if (n <= 1) return false;
        else if (n <= 3) return true;
        else if (n % 2 == 0 || n % 3 == 0) return false;
        int i = 5;
        while (i * i <= n) {
            if (n % i == 0 || n % (i + 2) == 0) return false;
            i += 6;
        }
        return true;
    }
public:
    int maximumPrimeDifference(vector<int>& nums) {
        int s=0,e=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(isPrime(nums[i])){
                s=i; break;
            }
        }
        for(int i=n-1;i>=0;i--){
            if(isPrime(nums[i])){
                e=i; break;
            }
        }
        return e-s;
    }
};