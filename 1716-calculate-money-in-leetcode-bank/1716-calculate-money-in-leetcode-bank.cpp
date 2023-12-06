class Solution {
public:
    int totalMoney(int n) {
        int a=n/7;
        int b=n%7;
        long long ans=0;
        int i=0;
        while(i<a){
            ans=ans+ 28 + 7*(i);
            i++;
        }
        ans=ans + b*(b+1)/2 + a*b;
        
        return ans;
    }
};