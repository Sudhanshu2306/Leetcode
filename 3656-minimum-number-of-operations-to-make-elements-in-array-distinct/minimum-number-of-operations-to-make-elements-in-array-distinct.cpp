class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n=nums.size(); int count=0;
        set<int> st;
        for(int i=n-1;i>=0;i--){
            if(st.find(nums[i])!=st.end()) return (i+3)/3;
            else st.insert(nums[i]);
        }
        return count;
    }
};