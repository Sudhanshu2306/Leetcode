class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int x=0;int y; int n=nums.size();
        vector<int>ans(n+1);
        for(auto i:nums){
            x^=i;
            ans[i]++;
            if(ans[i]==2) y=i;
        }
        
        for(int i=1;i<=n;i++){
            x^=i;
        }
        x=x^y;
        return {y,x};
    }
};