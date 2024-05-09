class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.rbegin(),happiness.rend());
        long long sum=0;
        int d=0;
        for(auto i:happiness){
            sum+=max(0LL,(long long)i-d);
            d++;
            k--;
            if(k==0)break;
        }
        
        return sum;
    }
};