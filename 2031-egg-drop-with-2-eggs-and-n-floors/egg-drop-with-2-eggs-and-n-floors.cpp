class Solution {
public:
    int twoEggDrop(int n) {
        int i;
        for(i=0;i<n;i++){
            if(i*(i+1)>=2*n)break;
        }
        return i;
    }
};