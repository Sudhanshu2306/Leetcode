class Solution {
public:
    int trap(vector<int>& a) {
        int n=a.size();
        int ans=0;
        int lmax=0,rmax=0;
        int i=0,j=n-1;

        while(i<=j){
            if(a[i]<=a[j]){
                if(lmax>a[i]){
                    ans+=(lmax-a[i]);
                }
                else lmax=a[i];
                i++;
            }
            else{
                if(rmax>a[j]){
                    ans+=(rmax-a[j]);
                }
                else rmax=a[j];
                j--;
            }
        }
        return ans;
    }
};