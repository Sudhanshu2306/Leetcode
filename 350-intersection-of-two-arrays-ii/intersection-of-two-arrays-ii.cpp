class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        
        for(auto i:nums1){
            mp[i]++;
        }
        nums1.clear();
        for(auto i:nums2){
            if(mp.find(i)!=mp.end()){
                nums1.push_back(i);
                mp[i]--;
                if(mp[i]==0)mp.erase(i);
            } 
        }
        return nums1;
    }
};