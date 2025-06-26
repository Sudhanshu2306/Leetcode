typedef long long ll;
class Solution {
public:
    long long putMarbles(vector<int>& v, int k) {
        int n=v.size();
        ll mx=v[0]+v[n-1];
        ll mn=v[0]+v[n-1]; 
        
        vector<ll> x; 
        
        for(int i=0;i<n-1;i++) x.push_back(v[i]+v[i+1]);  
        sort(x.begin(),x.end()); 
        
        for(int i=0;i<k-1;i++){
            mn+=x[i];
            mx+=x[n-i-2];
        }  
        
    
        return (mx-mn); 
    }
};