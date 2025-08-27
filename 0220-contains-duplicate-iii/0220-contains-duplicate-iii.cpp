class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int id, int vd) {
        int n=nums.size();
        int i=0, j=0;
        set<int> st;
        while(j<n){
            auto it=st.lower_bound(nums[j]);
            int mini=1e9;
            if(it!=st.end()){
                mini=min(mini,abs(*it-nums[j]));
            }
            if(it!=st.begin()){
                it--;
                mini=min(mini,abs(*it-nums[j]));
            }
            if(mini<=vd) return true;
            if(st.size()<id) st.insert(nums[j]);
            else{
                st.erase(nums[i]);
                i++; st.insert(nums[j]);
            }
            j++;
        }
        return false;
        
    }
};