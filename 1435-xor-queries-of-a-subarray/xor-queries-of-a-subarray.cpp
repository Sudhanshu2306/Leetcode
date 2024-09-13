class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& q) {
        int n=arr.size();
        vector<int> pre(n);
        int x=arr[0];
        pre[0]=arr[0]; 
        for(int i=1;i<n;i++){
            pre[i]=arr[i]^pre[i-1];
            x^=arr[i];
        }
        // for(int i=n-2;i>=0;i--){
        //     suf[i]=arr[i]^suf[i+1];
        // }
        vector<int> ans;
        for(int i=0;i<q.size();i++){
            int l=q[i][0],r=q[i][1];
            int y=pre[r];
            if(l>0) y^=pre[l-1];
            // if(r<n-1) y^=suf[i+1];
            ans.push_back(y);
        }
        return ans;
    }
};