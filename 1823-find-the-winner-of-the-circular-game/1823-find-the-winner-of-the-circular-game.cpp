class Solution {
public:
    int findTheWinner(int n, int k) {
        int last=0;
        for(int i=0;i<n;i++){
            last=(last+k)%(i+1);
        }
        return last+1;
    }
};