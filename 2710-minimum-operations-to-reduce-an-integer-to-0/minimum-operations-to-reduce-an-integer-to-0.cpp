class Solution {
public:
    int minOperations(int n) {
        int count=0;
        while(n){
            if((n&3)==3){
                n++; count++;
            }
            else{
                if(n%2==1) count++;
                n>>=1;
            }
        }
        return count;
    }
};