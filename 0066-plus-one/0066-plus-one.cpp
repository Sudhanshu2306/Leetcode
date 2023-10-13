class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        
        vector<int> ans(n+1,0);
        for(int i=n-1;i>=0;i--){
            ans[i+1]=digits[i];
        }
        
        if(digits[n-1]<9){
            digits[n-1]+=1;
            return digits;
        }
        else{
            ans[n]+=1;
            for(int i=n;i>=0;i--){
                if(ans[i]==10){
                    ans[i]=0;
                    ans[i-1]+=1;
                }
            }
        }
        if(ans[0]==0){
            ans.erase(ans.begin());
        }
        
        return ans;
    } 
};