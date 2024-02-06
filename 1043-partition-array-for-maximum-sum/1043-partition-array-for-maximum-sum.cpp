class Solution {
public:

    int f(int ind, vector<int> &arr, int k, vector<int> &dp){
        // base case
        if(ind==arr.size()) return 0;

        if(dp[ind]!=-1) return dp[ind];
        // index element se lekar k elements tak traverse karte h
        // keep in mind j+k can exceed arr.size() for last elements, so take minimum of n and (j+k)
        int maxi=INT_MIN;
        int count=0;
        int maxAns=INT_MIN;
        for (int j = ind; j < std::min(ind + k, static_cast<int>(arr.size())); j++) {            
            count++;
            maxi=max(maxi,arr[j]);
            int sum=maxi*count+f(j+1,arr,k,dp);
            maxAns=max(maxAns,sum);
        }
        return dp[ind]= maxAns;
    }

    int tabulation(vector<int>& arr, int k){
        int n=arr.size();
        vector<int> dp(n+1,0);

        // base case : already all elements are zero

        for(int ind=n-1;ind>=0;ind--){
            int maxi=INT_MIN;
            int count=0;
            int maxAns=INT_MIN;
            for (int j = ind; j < std::min(ind + k, static_cast<int>(arr.size())); j++) {            
                count++;
                maxi=max(maxi,arr[j]);
                int sum=maxi*count+dp[j+1];
                maxAns=max(maxAns,sum);
            }
            dp[ind]= maxAns;
        }
        return dp[0];
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        /*
        int n=arr.size();
        vector<int> dp(n,-1);
        return f(0,arr,k,dp);
        */
        
        return tabulation(arr,k);
    }
};