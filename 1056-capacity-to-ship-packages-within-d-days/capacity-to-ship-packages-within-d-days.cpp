class Solution {
public:
    bool f(vector<int>& a, int ul, int days){
        int wt=0; int count=1;
        for(int i=0;i<a.size();i++){
            if(wt+a[i]>ul){
                wt=a[i];
                count+=1;
            }
            else{
                wt+=a[i];
            }
        }
        if(count<=days) return true;
        return false;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int s=*max_element(weights.begin(),weights.end());
        int e=accumulate(weights.begin(),weights.end(),0);

        int ans=0;
        while(s<=e){
            int mid=s+(e-s)/2;

            bool x=f(weights,mid,days);
            if(x){
                ans=mid;
                e=mid-1;
            } 
            else s=mid+1;
        }
        return ans;
    }
};