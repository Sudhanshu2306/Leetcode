class Solution {
public:
    int countnum(int n , long long curr, long long next){
        int count=0;
        while(curr<=n){
            count+=min(next,(long long)n+1)-curr;
            curr*=10; next*=10;

        }
        return count;
    }
    int findKthNumber(int n, int k) {
        int curr=1;
        k--;
        while(k>0){
            int count=countnum(n,curr,curr+1);
            if(count<=k){
                curr++;
                k-=count;

            }
            else{
                curr*=10;
                k--;
            }
        }
        return curr;
    }
    
    
};