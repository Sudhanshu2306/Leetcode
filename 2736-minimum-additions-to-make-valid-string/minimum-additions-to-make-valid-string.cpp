class Solution {
public:
    int addMinimum(string s) {
        int n=s.size();
        int count=0;
        int i=0;
        while(i<n){
            string x=s.substr(i,2);
            if(s.substr(i,3)=="abc") i+=3;
            else if(x=="ab" || x=="bc" || x=="ac"){
                i+=2; count++;
            } 
            else {
                count+=2;
                i++;
            }
        }
        return count;
    }
};