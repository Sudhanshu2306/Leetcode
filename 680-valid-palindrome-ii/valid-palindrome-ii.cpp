class Solution {
public:
    bool validPalindrome(string s) {
        int i=0,j=s.size()-1;
        int x=0;

        while(i<j){
            if(s[i]!=s[j]) break;
            else{i++; j--;}
        }
        int i1=i,j1=j;
        i++;
        bool f1=true,f2=true;
        while(i<j){
            if(s[i]!=s[j]){
                f1=false; break;
            } 
            else{i++; j--;}
        }
        j1--;
        while(i1<j1){
            if(s[i1]!=s[j1]){
                f2=false; break;
            }
            else{i1++; j1--;}
        }
        return f1 | f2;
    }
};