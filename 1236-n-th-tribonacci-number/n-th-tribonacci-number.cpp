class Solution {
public:
    int tribonacci(int n) {
        if(n==0 || n==1)
            return n;
        if(n==2)
            return 1;
        
        int p=0,p1=1,p2=1;
        int curr;
        for(int i=3;i<=n;i++){
            curr=p+p1+p2;
            p=p1;
            p1=p2;
            p2=curr;
        }
        return curr;
    }
};