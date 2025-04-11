class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count=0;
        for(int i=low;i<=high;i++){
            string x=to_string(i);
            if(x.size()%2==0){
                int h1=0,h2=0;
                for(int j=0;j<x.size();j++){
                    if(j<x.size()/2) h1+=(x[j]-'0');
                    else h2+=(x[j]-'0');
                }
                if(h1==h2) count++;
            }
        }
        return count;
    }
};