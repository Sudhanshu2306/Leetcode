class Solution {
public:
    int numberOfSteps(int num) {
        int count=0;
        if(num==0) return 0;
        while(num>0){
            if(num&1) count+=2;
            else count+=1;
            num/=2;
        }
        return count-1;
    }
};