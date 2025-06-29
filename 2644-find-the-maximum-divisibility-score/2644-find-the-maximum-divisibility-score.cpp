class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        int maxi=0;
        int x=0;
        for(auto it:divisors){
            int count=0;
            for(auto i:nums){
                if(i%it==0) count++;
            }
            if(count>maxi){
                maxi=count;
                x=it;
            }
            if(count==maxi){
                if(x>it) x=it;
            }
        }
        return x;
    }
};