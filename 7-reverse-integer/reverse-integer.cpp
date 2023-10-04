
class Solution {
public:
    int reverse(int x) {
        long sum=0;
        int y=abs(x);
        while(y>0){
            int rem=y%10;
            sum=sum*10 + rem;
            y=y/10; 
        }
        if(sum>INT_MAX || sum<INT_MIN) return 0;
        
        if(x>0){
            return sum;
        }
        else{
            return -(sum);
        }
    }
};