class Solution {
public:
    int minOperations(vector<int>& nums) {
        bool flag=false;
        int n=nums.size();
        int z=nums.back()!=1;
        for(int i=0;i<n-1;i++){
            if(nums[i]!=1) z++;
            if(__gcd(nums[i],nums[i+1])==1){
                flag=true; 
            }
        }
        if(flag) return z;
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
        if(flag) return y+n;
        return -1;
    }
};