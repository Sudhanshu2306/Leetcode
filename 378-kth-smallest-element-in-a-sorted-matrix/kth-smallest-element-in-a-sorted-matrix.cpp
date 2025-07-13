class Solution {
public:
    int kthSmallest(vector<vector<int>>& a, int k) {
        int n=a.size();
        int s=a[0][0], e=a[n-1][n-1];

        while(s<e){
            int mid=s+(e-s)/2;

            int x=0;
            for(int i=0;i<n;i++){
                auto it=upper_bound(a[i].begin(),a[i].end(),mid)-a[i].begin();
                x+=it;
            }
            if(x>=k) e=mid;
            else s=mid+1;
        }
        return s;
    }
};