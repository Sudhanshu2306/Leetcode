class Solution {
public:
    int minSwaps(string s) {
        // stack<char> st;
        int sz=0;
        for(auto ch:s){
            if(ch=='[') sz++;
            else if(sz>0) sz--;
        }
        return (sz+1)/2;;
    }
};