class Solution {
public:
    long long maximumCoins(vector<vector<int>>& coins, int k) {
        int n=coins.size();
        sort(coins.begin(),coins.end());

        int i=0; int j=0;
        long long curr_coins=0;
        long long ans=0;
        while(i<n){
            while(j<n && coins[j][1]<=coins[i][0]+k-1){
                curr_coins+=1ll*(coins[j][1]-coins[j][0]+1)*coins[j][2];
                j++;
            }
            if(j<n){
                long long rem=max(0LL,1ll*(coins[i][0]+k-coins[j][0])*coins[j][2]);
                ans=max(ans,curr_coins+rem);
            }
            curr_coins-=1ll*(coins[i][1]-coins[i][0]+1)*coins[i][2];
            i++;
        }

        curr_coins=0;
        i=0,j=0;
        while(i<n){
            curr_coins+=1ll*(coins[i][1]-coins[i][0]+1)*coins[i][2];
            while(coins[j][1]<coins[i][1]-k+1){
                curr_coins-=1ll*(coins[j][1]-coins[j][0]+1)*coins[j][2];
                j++;
            }
            long long extra=max(0LL,1ll*(coins[i][1]-k-coins[j][0]+1)*coins[j][2]);
            ans=max(ans,curr_coins-extra);
            i++;
        }
        return ans;
    }
};