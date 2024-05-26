class Solution {
public:
    long long f(vector<int> &a, int d){
        long long ans=0;
        for(int i=0;i<a.size();i++){
            ans+=(ceil((double)a[i]/(double)d));
        }
        return ans;
    }

    int smallestDivisor(vector<int>& nums, int h) {
        int e=*max_element(nums.begin(),nums.end());
        int s=1;
        while(s<=e){
            int mid=s+(e-s)/2;
            long long x=f(nums,mid);
            if(x<=h){
                e=mid-1;
            }
            else s=mid+1;
        }
        return s;
    }
};