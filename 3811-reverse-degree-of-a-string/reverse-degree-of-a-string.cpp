class Solution {
public:
    int reverseDegree(string s) {
        int x=0;
        int i=1;
        for(auto it:s){
            x+=(i*(26-(it-'a')));
            i++;
        }
        return x;
    }
};