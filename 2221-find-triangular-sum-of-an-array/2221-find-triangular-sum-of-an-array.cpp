class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n=nums.size(); int a=n;
        vector<int> x=nums;
        while(a--){
            vector<int> y;
            for(int i=0;i<x.size()-1;i++){
                int sum=(x[i]+x[i+1])%10;
                y.push_back(sum);
            }
            x=y;
        }
        return x[0];
    }
};