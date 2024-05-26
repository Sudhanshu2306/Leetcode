class Solution {
public:
    bool f(vector<int>a, int l, int m, int k){
        for(int i=0;i<a.size();i++){
            if(a[i]<=l) a[i]=0;
            else a[i]=-1;
        }
        int count=0;
        int ans=0;
        for(int i=0;i<a.size();i++){
            if(a[i]==0) count++;
            else{
                if(count>=k) ans+=(count/k);
                count=0;
            }
        }
        if(count>=k) ans+=(count/k);
        return ans>=m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        // long long p=m*k;
        // if(p>bloomDay.size()) return -1;
        int e=*max_element(bloomDay.begin(),bloomDay.end());
        int s=*min_element(bloomDay.begin(),bloomDay.end());
        int ans=-1;
        while(s<=e){
            int mid=s+(e-s)/2;

            bool x=f(bloomDay,mid,m,k);
            if(x){
                ans=mid;
                e=mid-1;
            }
            else s=mid+1;
        }
        // for(auto i:bloomDay) cout<<i<<" ";
        return ans;
    }
};