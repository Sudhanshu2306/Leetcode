class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> mp;
        vector<int> ans;
        stack<int> st;
        int n=nums2.size();
        mp[nums2[n-1]]=-1;
        st.push(nums2[n-1]);
        for(int i=n-2;i>=0;i--){
            while(!st.empty() && st.top()<nums2[i]) st.pop();

            if(st.empty()) mp[nums2[i]]=-1;
            else mp[nums2[i]]=st.top();
            st.push(nums2[i]);
        }
        for(auto it:nums1){
            if(mp.find(it)==mp.end()) ans.push_back(-1);
            else{
                ans.push_back(mp[it]);
            }
        }
        return ans;
    }
};