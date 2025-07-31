class Solution {
public:
    int numTrees(int n) {
        if(n<=1) return 1;

        int count=0;
        for(int i=1;i<=n;i++){ // taking every number as root
            int subpart=numTrees(i-1)*numTrees(n-i);
            count+=subpart;
        }
        return count;
    }
};