class Solution {
public:
    int numSteps(string s) {
        int n=s.size();
        
        int count=0;
        int carry=0;

        for(int i=n-1;i>0;i--){
            if((s[i]-'0'+carry)%2==0){
                count++;
            }
            else{
                count+=2;
                carry=1;
            }
        }

        return carry>0?count+carry:count;
    }
};