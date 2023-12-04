class Solution {
public:
    string largestGoodInteger(string num) {
        int maxi=0;
        for(int i=0;i<num.length()-2;i++){
            if(num[i]==num[i+1] && num[i]==num[i+2]){
                if(num[i]>maxi){
                    maxi=num[i];
                }
            }
        }
        if(maxi==0){
            return "";
        }
        else{
            string x(3,maxi);
            return x;
        }
    }
};