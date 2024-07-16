class Solution {
public:
    int trap(vector<int>& heights) {
        int n=heights.size();
        vector<int> pre(n); pre[0]=heights[0];
        vector<int> suf(n); suf[n-1]=heights[n-1];

        for(int i=1;i<n;i++){
            pre[i]=max(pre[i-1],heights[i]);
        }
        for(int i=n-2;i>=0;i--){
            suf[i]=max(suf[i+1],heights[i]);
        }
        int water=0;
        for(int i=0;i<n;i++){
            if((min(pre[i],suf[i]))-heights[i]>0){
                water+=min(pre[i],suf[i])-heights[i];
            }
        }
        return water;
    }
    /*
    int trap(vector<int>& heights){
        int n=heights.size();
        int l=0,r=n-1;
        int lmaxi=0,rmaxi=0;
        int water=0;

        while(l<=r){
            if(heights[l]<=heights[r]){
                if(heights[l]>lmaxi) lmaxi=heights[l];
                else water+=(lmaxi-heights[l]);
                l++;
            }
            else{
                if(heights[r]>rmaxi) rmaxi=heights[r];
                else water+=(rmaxi-heights[r]);
                r--;
            }
        }
        return water;
    }
    */
};