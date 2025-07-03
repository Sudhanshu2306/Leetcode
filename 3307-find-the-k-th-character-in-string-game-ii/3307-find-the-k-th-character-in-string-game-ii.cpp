class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        if(k==1) return 'a';

        int n=operations.size();
        long long newK=-1, oper=-1;
        long long len=1;
        for(int i=0;i<n;i++){
            len*=2;
            if(len>=k){
                newK=k-len/2;
                oper=operations[i];
                break;
            }
        }
        char ch=kthCharacter(newK,operations);
        if(oper==0) return ch;
        else{
            return ch=='z'?'a':ch+1;
        }
    }
};