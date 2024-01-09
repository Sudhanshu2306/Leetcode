class Solution {
public:
    long long minimumSteps(string s) {
        string x=s;
        sort(x.begin(),x.end());
        if(x==s) return 0;
        int n=s.length();
        long long last=0;
        long long count=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='0'){
                last+=1; 
            }
            else{
                count+=last;
            }
        }
        return count;
    }
};