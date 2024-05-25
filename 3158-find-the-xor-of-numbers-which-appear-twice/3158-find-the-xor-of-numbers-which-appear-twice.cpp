class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        unordered_set<int>st;
        for(int i:nums) st.insert(i);
        int ans=0;
        for(auto i:st) ans^=i;
        for(auto i:nums) ans^=i;
        
        return ans;
    }
};