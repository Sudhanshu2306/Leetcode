class Solution {
public:
    int passThePillow(int n, int time) {
        int x=time%(n-1);
        int y=time/(n-1);

        if(y%2==0){
            return x+1;
        }
        else{
            return n-x;
        }
    }
};