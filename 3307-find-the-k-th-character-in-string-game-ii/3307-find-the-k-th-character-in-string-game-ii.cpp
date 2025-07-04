class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        int n=operations.size();
        if(k==1) return 'a';

        long long newK=-1, op=-1;
        long long len=1;
        for(int i=0;i<n;i++){
            len*=2;
            if(len>=k){
                newK=k-len/2;
                op=operations[i]; break;
            }
        }
        char ch=kthCharacter(newK,operations);
        if(op==0){
            return ch;
        }
        else{
            if(ch=='z') return 'a';
            else return ch+1;
        } 
    }
};