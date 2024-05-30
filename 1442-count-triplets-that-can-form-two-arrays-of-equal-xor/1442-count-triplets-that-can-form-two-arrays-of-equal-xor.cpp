class Solution {
public:
    int countTriplets(vector<int>& arr) {
        
        vector<int>pre=arr;

        // pre[0]=arr[0];
        pre.insert(pre.begin(),0);

        int n=pre.size();
        for(int i=1;i<n;i++){
            pre[i]^=pre[i-1];
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(pre[i]==pre[j]) ans+=(j-i-1);
            }
        }
        return ans;
    }
};