class Solution {
public:
    int maxDistance(string x, int k) {
        int n=0,s=0,e=0,w=0;
        int maxi=0;
        for(auto it:x){
            if(it=='N') n++;
            else if(it=='S') s++;
            else if(it=='E') e++;
            else w++;

            int curr=abs(e-w)+abs(n-s);
            int minix=min(e,w), miniy=min(s,n);
            if(minix+miniy>=k) curr+=2*k;
            else curr+=2*(minix+miniy);

            maxi=max(maxi,curr);
        }
        return maxi;
    }
};