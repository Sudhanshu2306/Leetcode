class Solution {
public:
    int strStr(string h, string n) {
        int x=h.size();
        int y=n.size();
        // int index=0;
        for(int i=0;i<=x-y;i++){
            if(h.find(n)!=string::npos) return h.find(n);
        }
        return -1;
    }
};