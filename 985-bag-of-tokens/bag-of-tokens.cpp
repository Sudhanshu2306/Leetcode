class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int maxi=0;
        sort(tokens.begin(),tokens.end());
        int n=tokens.size();
        int r=n-1; int l=0;
        int ans=0;

        while(l<=r && (power>=tokens[l] || ans>0)){
            if(power>=tokens[l]){
                power-=tokens[l++];
                ans++;
                maxi=max(ans,maxi);
            }
            else if(ans>0){
                power+=tokens[r--];
                ans--;
            }
        }
        return maxi;
    }
};