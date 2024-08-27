class Solution {
public:
    int f(vector<int> &a, int mid, int k){
        int count=0;
        for(int i=0;i<a.size();i++){
            if(a[i]<=mid){
                count++; i++;
            }
        }
        return count>=k;
    }

    int minCapability(vector<int>& nums, int k) {
        // if i can rob x amount of money, definately I can also rob x+1,x+2 ..
        long long s=*min_element(nums.begin(),nums.end());
        long long e=*max_element(nums.begin(), nums.end());

        long long ans=1e9;
        while(s<=e){
            long long mid=s+(e-s)/2;
            if(f(nums,mid,k)){
                ans=mid;
                e=mid-1;
            }
            else s=mid+1;
        }
        return ans;
    }
};