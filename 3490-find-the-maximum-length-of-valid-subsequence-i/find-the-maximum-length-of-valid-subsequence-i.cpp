class Solution {
public:
    
    int maximumLength(vector<int>& nums) {
        int even=0,odd=0;
        for(auto it:nums){
            even+=(it%2==0);
            odd+=(it%2==1);
        }
        int x=0,y=0;
        for(auto it:nums){
            if(it%2==0) x=max(x,y+1);
            else y=max(y,x+1);
        }
        return max({x,y,even,odd});
    }
};