class Solution {
public:
    long long minEnd(int n, int x) {
        long long ans=x;

        vector<long long> temp;
        for(int i=0;i<64;i++){
            if(((ans>>i)^1)&1){
                temp.push_back(i);
            }
        }
        long long mask=n-1;
        for(int i=0;i<temp.size();i++){
            if((mask>>i)&1LL) ans|=(1LL<<temp[i]);
        }
        return ans;
    }
};