class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        // it can be broken down into sum of subarray maximum - sum of subarray minimum
        int n=nums.size();
        vector<int> pse(n),nse(n);
        vector<int> pge(n),nge(n);

        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]>nums[i]) st.pop();

            if(st.empty()) pse[i]=-1;
            else pse[i]=st.top();

            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]>=nums[i]) st.pop();

            if(st.empty()) nse[i]=n;
            else nse[i]=st.top();

            st.push(i);
        }

        int sum=0;
        int ans=0;
        for(int i=0;i<n;i++){
            int left=i-pse[i];
            int right=nse[i]-i;
            sum+=(1LL*left*right*nums[i]);
        }
        ans-=sum; sum=0;
        while(!st.empty()) st.pop();
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]<nums[i]) st.pop();

            if(st.empty()) pge[i]=-1;
            else pge[i]=st.top();

            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]<=nums[i]) st.pop();

            if(st.empty()) nge[i]=n;
            else nge[i]=st.top();

            st.push(i);
        }
        for(int i=0;i<n;i++){
            int left=i-pge[i];
            int right=nge[i]-i;
            sum+=(1LL*left*right*nums[i]);
        }
        ans+=sum;
        return ans;
    }
};