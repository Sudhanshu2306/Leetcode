class Solution {
public:
    vector<int> seive(int n){
        vector<int> prime(n+1,true);
        for(int i=2;i*i<=n;i++){
            if(prime[i]){
                for(int j=i*i;j<=n;j+=i){
                    prime[j]=false;
                }
            }
        }
        return prime;
    }
    int distinctPrimeFactors(vector<int>& nums) {
        int maxi=*max_element(nums.begin(),nums.end());
        vector<int> prime=seive((maxi)+1);

        unordered_set<int> st;
        for(int i=0;i<nums.size();i++){
            for(int j=2;j<=maxi;j++){
                if(prime[j] && j<=nums[i]){
                    if(nums[i]%j==0) st.insert(j);
                }
            }
        }
        for(auto i:st){
            cout<<i<<" ";
        }
        return st.size();
    }
};