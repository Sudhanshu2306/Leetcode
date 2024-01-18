class Solution {
public:
    
    int solve(int ind){
        if(ind==1 || ind==0) return 1;
        
        int x = solve(ind-1);
        int y = solve(ind-2);
        
        return x+y;
    }
    
    int climbStairs(int n) {
        // base case
        // return solve(n);
        if(n==0 || n==1){
            return 1;
        }
        int prev=1; int curr=1;
        
        for(int i=2;i<=n;i++){
            //tabulation
            int temp=curr;
            curr=prev+curr;
            prev=temp;
        }
        return curr;
    }
};
