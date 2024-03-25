class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;

        for(auto i:nums) {
            if(nums[abs(i)-1]<0) {
                ans.push_back(abs(i));
            }
            else {
                nums[abs(i)-1] *= -1;
            }   
        }
        return ans;
    }
};