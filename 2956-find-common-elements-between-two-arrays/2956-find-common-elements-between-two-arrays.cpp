class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> a,b;
        int a1=0,b1=0;
        for(int i=0;i<nums1.size();i++){
            a.insert(nums1[i]);
        }
        for(int i=0;i<nums2.size();i++){
            b.insert(nums2[i]);
            if(a.find(nums2[i])!=a.end()){
                a1++;
            }
        }
        for(int i=0;i<nums1.size();i++){
            if(b.find(nums1[i])!=b.end()){
                b1++;
            }
        }
        vector<int> ans={b1,a1};
        return ans;
    }
};