class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st1,st2;
        for(auto i:nums1) st1.insert(i);
        
        for(auto i:nums2){
            if(st1.find(i)!=st1.end()) st2.insert(i);
        }
        nums1.clear();
        for(auto i:st2){
            nums1.push_back(i);
        }
        return nums1;
    }
};