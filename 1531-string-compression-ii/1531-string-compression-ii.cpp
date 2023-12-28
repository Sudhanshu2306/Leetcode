class Solution {
public:
    
    int getLength(int count){
        return count==1? 1:(count<10? 2:(count<100?3:4));
    }
    
    int getLengthOfOptimalCompression(string s, int k) {
        int n=s.length();
        int dp[n+1][k+1];
        
        for(int i=n;i>=0;i--){
            for(int j=0;j<=k;j++){
                if(i==n){
                    dp[n][j]=0;
                    continue;
                }
                    
                dp[i][j] = j>0? dp[i+1][j-1]:INT_MAX;
                
                int pd=j,count=0;
                for(int l=i;l<n && pd>=0;l++){
                    if(s[l]==s[i]){
                        count++;
                        dp[i][j]=min(dp[i][j],getLength(count)+dp[l+1][pd]);
                    }
                    else{
                        pd--;
                    }
                }
            }
        }
        return dp[0][k];
    }
};