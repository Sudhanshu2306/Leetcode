class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n=code.size();
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            int x=0;
            if(k<0){
                for(int j=1;j<=abs(k);j++){
                    x+=code[(n+i-j)%n];
                }
                ans[i]=x;
            }
            else if(k>0){
                for(int j=1;j<=abs(k);j++){
                    x+=code[(i+j)%n];
                }
                ans[i]=x;
            }
            else ans[i]=x;
        }
        return ans;
    }
};