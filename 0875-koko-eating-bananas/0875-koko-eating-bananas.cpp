class Solution {
public:

    long long f(vector<int> &a, int d){
        long long ans=0;
        for(int i=0;i<a.size();i++){
            ans+=(ceil((double)a[i]/(double)d));
        }
        return ans;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int e=*max_element(piles.begin(),piles.end());
        int s=1;
        while(s<=e){
            int mid=s+(e-s)/2;
            long long x=f(piles,mid);
            if(x<=h){
                e=mid-1;
            }
            else s=mid+1;
        }
        return s;
    }
};