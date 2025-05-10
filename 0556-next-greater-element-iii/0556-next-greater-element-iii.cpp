class Solution {
public:
    int nextGreaterElement(int n) {
        string x=to_string(n);
        next_permutation(begin(x),end(x));
        int y=stoll(x);
        if(y>INT_MAX || y<=n) return -1;
        return y;
    }
};