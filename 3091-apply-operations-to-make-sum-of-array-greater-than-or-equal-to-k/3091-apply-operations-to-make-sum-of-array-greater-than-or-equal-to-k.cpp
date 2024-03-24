class Solution {
public:
    int minOperations(int k) {
        if(k==1) return 0;
        int mini=INT_MAX;
        for(int i=1;i*i<=k;i++){
            int a=k/i; 
            int b=k%i;
            if(b==0){
                mini=min(mini,(a+i-2));
            }
            else{
                mini=min(mini,(a+i-1));
            }
            
        }
        return mini;
    }
};