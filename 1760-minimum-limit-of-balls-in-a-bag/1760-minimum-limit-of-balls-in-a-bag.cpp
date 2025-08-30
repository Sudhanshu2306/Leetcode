typedef long long ll;
class Solution {
public:
    int totalBalls;
    bool f(int mid, vector<int> &nums){
        ll count=0;
        for(auto it:nums){
            if(it%mid==0) count+=(it/mid);
            else count+=(it/mid)+1;
        }
        return count<=totalBalls;
    }
    int minimumSize(vector<int>& nums, int maxOP) {
        totalBalls=nums.size()+maxOP;
        int n=nums.size();

        ll s=1, e=1e9;
        ll ans=e;
        while(s<=e){
            ll mid=s+(e-s)/2;

            if(f(mid,nums)){
                ans=mid;
                e=mid-1;
            }
            else s=mid+1;
        }
        return ans;
    }
};