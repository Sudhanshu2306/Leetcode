long long mod=1e9+7;

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        long long ans=0;
        stack<long long> s1,s2;
        vector<long long> next(n),prev(n);
        for(int i=0;i<n;i++){
            prev[i]=i;
            next[i]=n-i-1;
        }
        for(int i=0;i<n;i++){
            while(!s1.empty() && arr[s1.top()]>arr[i]){
                next[s1.top()]=i-s1.top()-1;
                s1.pop();
            }
            s1.push(i);
        }

        for(int i=n-1;i>=0;i--){
            while(!s2.empty() && arr[s2.top()]>=arr[i]){
                prev[s2.top()]=s2.top()-i-1;
                s2.pop();
            }
            s2.push(i);
        }

        for(int i=0;i<n;i++){
            ans+=static_cast<long long>((next[i]+1)*(prev[i]+1)*arr[i]);
            ans%=mod;
        }
        
        return ans%mod;
    }
};