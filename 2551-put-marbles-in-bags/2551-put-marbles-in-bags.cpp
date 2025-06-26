class Solution {
public:
    long long putMarbles(vector<int>& v, int k) {
        int n = v.size();
        
        long long  mx = v[0] + v[n-1]; // Maximum Value 
        long long  mn = v[0] + v[n-1]; // Minimum Value
        
        vector<long long > adjSum; 
        
        for(int i = 0;i<n-1;i++)
            adjSum.push_back(v[i] + v[i+1]);  
        
        sort(adjSum.rbegin(),adjSum.rend()); 
        
        for(int i = 0;i<k-1;i++)
            mx +=(long long) adjSum[i],
            mn +=(long long) adjSum[n-i-2]; 
    
        return (mx- mn); 
    }
};