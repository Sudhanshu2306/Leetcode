class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        // it can be broken down into sum of subarray maximum - sum of subarray minimum
        long long n=nums.size();
        vector<long long> pse(n),nse(n);
        vector<long long> pge(n),nge(n);

        stack<long long> st;
        for(long long i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]>nums[i]) st.pop();

            if(st.empty()) pse[i]=-1;
            else pse[i]=st.top();

            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(long long i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]>=nums[i]) st.pop();

            if(st.empty()) nse[i]=n;
            else nse[i]=st.top();

            st.push(i);
        }

        long long sum=0;
        long long ans=0;
        for(long long i=0;i<n;i++){
            long long left=i-pse[i];
            long long right=nse[i]-i;
            sum+=(1LL*left*right*nums[i]);
        }
        ans-=sum; sum=0;
        while(!st.empty()) st.pop();
        for(long long i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]<nums[i]) st.pop();

            if(st.empty()) pge[i]=-1;
            else pge[i]=st.top();

            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(long long i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]<=nums[i]) st.pop();

            if(st.empty()) nge[i]=n;
            else nge[i]=st.top();

            st.push(i);
        }
        for(long long i=0;i<n;i++){
            long long left=i-pge[i];
            long long right=nge[i]-i;
            sum+=(1LL*left*right*nums[i]);
        }
        ans+=sum;
        return ans;
    }
};