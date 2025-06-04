class Solution {
public:
    string answerString(string s, int x) {
        int n=s.size();
        if(x==1) return s;
        string maxi="a";
        for(int i=0;i<n;i++){
            string y=s.substr(i,n+1-x);
            maxi=max(maxi,y);
        }
        return maxi;
    }
};