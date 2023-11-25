class Solution {
public:
    int addDigits(int num) {
        while(num%10!=num){
            int sum=0;
            int x=num;
            while(x>0){
                sum+=x%10;
                x/=10;
            }
            num=sum;
        }
        return num;
    }
    
};