class Solution {
public:
    bool isPowerOfFour(int n) {
        for(int i=0;i<16;i++){
            int x=pow(4,i);
            if(x==n){
              return true;
            }
            
        }
        return false;
    }
};

