class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        sort(coins.begin(),coins.end());
        int count=0;
        int obtainable=0;
        
        for(auto i:coins){
            while(i>obtainable+1){
                count++;
                int x=obtainable+1;
                obtainable+=x;
                if(obtainable>=target){
                    return count;
                }
            }
            obtainable+=i;
            if(obtainable>=target){
                return count;
            }
        }
        while(obtainable<target){
            count++;
            int x=obtainable+1;
            obtainable+=x;
        }
        return count;
    }
};

