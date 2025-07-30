class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        int count=0;
        int curr=1;
        sort(coins.begin(),coins.end());
        for(int i=0;i<coins.size() && curr<=target;i++){
            if(curr==coins[i]) curr*=2;
            else if(curr>coins[i]) curr+=coins[i];
            else{
                count++; curr*=2; i--;
            }
        }
        while(curr<=target){
            curr*=2;
            count++;
        }
        // if(curr<=target) return count+1;
        return count;
    }
};