typedef long long ll;
class Solution {
public: 
    bool f(vector<int> &a, ll mid, int k){
        ll sum=0;
        ll count=0;
        for(int i=0;i<a.size();i++){
            if(a[i]>mid) return false;
            else if(sum+a[i]<=mid) sum+=a[i];
            else{
                count++;
                sum=a[i];
                if(count>k) return false;
            }
        }
        return count==k;
    }
    int splitArray(vector<int>& nums, int k) {
        ll sum=accumulate(nums.begin(),nums.end(),0LL);
        ll maxi=*max_element(nums.begin(),nums.end());

        ll s=maxi,e=sum;

        while(s<e){
            ll mid=s+(e-s)/2;
            if(f(nums,mid,k-1)) e=mid;
            else s=mid+1;
        }
        return s;
    }
};