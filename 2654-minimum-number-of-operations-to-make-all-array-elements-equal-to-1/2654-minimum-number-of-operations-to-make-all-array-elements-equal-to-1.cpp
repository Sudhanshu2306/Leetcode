class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        bool flag=false;
        int count=(nums[0]!=1);
        for(int i=1;i<n;i++){
            count+=(nums[i]!=1);
            if(__gcd(nums[i],nums[i-1])==1) flag=true;
        }
        if(flag) return count;
        vector<int> x;
        for(int i=0;i<n-1;i++){
            x.push_back(__gcd(nums[i],nums[i+1]));
        }
        flag=false;
        int y=INT_MAX;
        for(int i=0;i<x.size();i++){
            for(int j=i+1;j<x.size();j++){
                if(__gcd(x[i],x[j])==1){
                    flag=true;
                    y=min(y,j-i);
                }
            }
        }
        return flag?y+n:-1;
    }
};