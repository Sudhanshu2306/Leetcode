class Solution {
public:
    bool checkValidString(string s) {
        int ans=0; int maxi=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                ans++; maxi++;
            }
            else if(s[i]==')'){
                ans--; maxi--;
            }
            else{
                ans--; maxi++;
            }
            ans=max(ans,0);
            if(maxi<0) return false;
        }
        if(ans==0) return true;
        return false;
    }
};