class Solution {
public:
    int maxFreqSum(string s) {
        vector<int> x(26,0);
        for(auto it:s) x[it-'a']++;
        int c=0,v=0;
        for(int i=0;i<26;i++){
            if(i==0 || i==4 || i==8 || i==14 || i==20) c=max(c,x[i]);
            else v=max(v,x[i]);
        }
        return c+v;
    }
};