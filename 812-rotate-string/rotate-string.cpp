class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s==goal) return true;
        int n=s.size(),m=goal.size();
        string x=s+s;
        if(n==m && x.find(goal)!=string::npos) return true;
        return false;
    }
};