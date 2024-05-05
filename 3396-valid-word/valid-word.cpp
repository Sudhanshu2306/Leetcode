class Solution {
public:
    bool isValid(string word) {
        int n=word.size();
        
        if(n>=3){
            int f1=0,f2=0,f3=0,f4=1;
            for(int i=0;i<n;i++){
                if((word[i]>='0'&&word[i]<='9')||(word[i]>='a'&&word[i]<='z') || (word[i]>='A'&&word[i]<='Z')) f1=1;
                if(word[i]=='a'||word[i]=='e'||word[i]=='i'||word[i]=='o'||word[i]=='u'||word[i]=='A'||word[i]=='E'||word[i]=='I'||word[i]=='O'||word[i]=='U') f2=1;
                if(((word[i]>='a'&&word[i]<='z')||(word[i]>='A'&&word[i]<='Z')) &&word[i]!='a'&&word[i]!='e'&&word[i]!='i'&&word[i]!='o'&&word[i]!='u'&&word[i]!='A'&&word[i]!='E'&&word[i]!='I'&&word[i]!='O'&&word[i]!='U') f3=1;
                if(word[i]=='@' || word[i]=='#' || word[i]=='$') return false;
            }
            if(f1&&f2&&f3) return true;
            else return false;
        }
        else{
            return false;
        }
    }
};