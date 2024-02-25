class Solution {
public:

    int f(int x){
        string y=to_string(x);
        reverse(y.begin(),y.end());
        int z=stoi(y);
        return z;
    }

    bool sumOfNumberAndReverse(int num) {
        for(int i=0;i<=num;i++){
            if(i+f(i)==num) return true;
        }
        return false;
    }
};