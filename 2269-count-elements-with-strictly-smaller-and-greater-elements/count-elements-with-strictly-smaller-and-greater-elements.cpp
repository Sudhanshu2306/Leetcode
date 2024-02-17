class Solution {
public:
    int countElements(vector<int>& nums) {
        int maxi=*max_element(nums.begin(),nums.end());
        int mini=*min_element(nums.begin(),nums.end());

        int count=0;
        for(auto i:nums){
            if(i>mini && i<maxi) count++;
        }
        return count;
    }
};