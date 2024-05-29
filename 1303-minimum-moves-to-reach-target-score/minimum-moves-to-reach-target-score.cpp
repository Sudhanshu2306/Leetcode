class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int count=0;
        while(target>1 && maxDoubles>0){
            if(target&1) count+=2;
            else count+=1;
            maxDoubles--;
            target/=2;
        }
        return count+target-1;
    }
};