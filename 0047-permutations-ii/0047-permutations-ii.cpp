// #include <boost/functional/hash.hpp>
struct VectorHash {
    std::size_t operator()(const std::vector<int>& v) const {
        std::hash<int> hasher;
        std::size_t result = 0;
        for (int i : v) {
            result ^= hasher(i) + 0x9e3779b9 + (result << 6) + (result >> 2);
        }
        return result;
    }
};
class Solution {
public:
    void solve(unordered_set <vector<int>,VectorHash> &ans, int index, vector<int> & nums){
        if(index>=nums.size()){
            ans.insert(nums);
            return;
        }
        for(int j=index;j<nums.size();j++){
            swap(nums[j],nums[index]);
            solve(ans, index+1, nums);
            swap(nums[j],nums[index]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> answer;
        unordered_set <vector<int>,VectorHash> ans;
        int index=0;
        solve(ans,index,nums);
        
        for(auto i:ans){
            answer.push_back(i);
        }
        return answer;
    }
};