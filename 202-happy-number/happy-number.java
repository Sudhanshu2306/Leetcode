class Solution {
    public boolean isHappy(int n) {
        if(n==1) return true;
        if(n>1 && n<=4) return false;
        int sum=0;
        while(n>0){
            int x=n%10;
            sum+=(x*x);
            n/=10;
        }
        return isHappy(sum);
    }
}