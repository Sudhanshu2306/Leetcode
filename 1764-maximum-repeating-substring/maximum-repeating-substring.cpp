class Solution {
public:
    int maxRepeating(string s, string t) {
        int n=s.size(); int m=t.size();

        int i=0;
        int count=0;
        int maxi=0;
        int j=0;
        while(j<n){
            if(s.substr(j,m)==t){
                count++; j+=m;
            }
            else{
                maxi=max(maxi,count);
                i++; j=i; count=0;
            }
            maxi=max(maxi,count);
        }
        return maxi;
    }
};