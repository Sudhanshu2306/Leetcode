class Solution {
public:
long long mod=1e9+7;
int modpower(long base, int exp) {long result = 1;while (exp) {if (exp & 1) {result *= base;result %= mod;}base *= base;base %= mod;exp >>= 1;}return result;}

    vector<int> getFinalState(vector<int>& nums, int k, int m) {
        int n=nums.size();
        if(m==1) return nums;
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> pq;
	    for(int i=0;i<n;i++){
	        pq.push({nums[i],i});
	        // j++;
	    }
        // sort(nums.begin(),nums.end());
	    long long ind=0;
        const long mx=*max_element(nums.cbegin(), nums.cend());
	    while(k>0 && 1LL*m *pq.top().first <= mx){
	        auto x=pq.top();
	        pq.pop();
	        long long num=x.first*m;
	        pq.push({num,x.second});
	        k--;
	    }
	    const long pow=modpower(m, k / n);
        while (!pq.empty()) {
            int val=pq.top().first;
            int ind=pq.top().second; pq.pop();

            if(k%n){
                --k;
                nums[ind]=((1LL*m*pow)%mod*val)%mod; 
            } 
            else nums[ind]=(1LL*pow*val)%mod;
            
        }
        return nums;
    }
};
