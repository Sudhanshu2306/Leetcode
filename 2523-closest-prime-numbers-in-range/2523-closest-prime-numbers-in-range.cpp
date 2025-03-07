class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool> isPrime(right+1,true);
        isPrime[1]=false;
        for(int i=2;i*i<=right;i++){
            if(isPrime[i]){
                for(int j=i*i;j<=right;j+=i) isPrime[j]=false;
            }
        }
        vector<int> p;
        for(int i=left;i<=right;i++) if(isPrime[i]) p.push_back(i);
        int mini=1e9+7;
        int x=-1,y=-1;
        if(p.size()<2) return {-1,-1};
        for(int i=0;i<p.size()-1;i++){
            if(mini>p[i+1]-p[i]){
                mini=p[i+1]-p[i];
                x=p[i]; y=p[i+1];
            }
        }
        return {x,y};
    }
};