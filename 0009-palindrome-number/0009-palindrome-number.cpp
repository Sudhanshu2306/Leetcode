class Solution {
public:
    bool isPalindrome(int x) {
        int y=abs(x);
        long sum=0;
        while(y>0){
            int rem=y%10;
            sum=sum*10+rem;
            y=y/10;
        }
        if(x>=0){
            if(x==sum){
                return true;
            }
            else{
                return false;
            }
        }
        else{
            return false;
        }
    }
};