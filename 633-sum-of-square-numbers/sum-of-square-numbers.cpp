class Solution {
public:
    bool judgeSquareSum(int c) {
        long long int e = sqrt(c);
        long long int s = 0; 

        while(s<=e){
            if(s*s + e*e == c){
                return true;
            }
            else if(s*s + e*e < c) s++;
            else e--;
        }
        return false;
    }
};