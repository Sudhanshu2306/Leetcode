class Solution {
public:
    int f(vector<int> &nums, vector<vector<int>> & q, int mid){
        int n=nums.size();
        vector<int> a(n+1,0);
        for(int i=0;i<mid;i++){
            int l=q[i][0], r=q[i][1], val=q[i][2];
            a[l]+=val;
            if(r+1<n) a[r+1]-=val;
        }
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=a[i];
            if(nums[i]>sum) return false;
        }
        return true;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int m=queries.size();
        int s=0,e=m;
        if(!f(nums,queries,m)) return -1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(f(nums,queries,mid)) e=mid-1;
            else s=mid+1;
        }
        return s;
    }
};