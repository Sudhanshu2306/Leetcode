class Solution {
public:
    int twoEggDrop(int n) {
        int i;
        for(i=1;i<n;i++){
            if(i*(i+1)>=2*n)break;
        }
        return i;
    }
};