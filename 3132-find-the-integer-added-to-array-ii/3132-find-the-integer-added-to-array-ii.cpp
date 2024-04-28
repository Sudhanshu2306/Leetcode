class Solution {
public:
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());

        for(int i = 2;i>=0;i--){
            int tmp;
            int cnt = 0;
            int cnt2 = 0;
            
            tmp = nums1[i] - nums2[0];
            for(int j = 0;j<nums1.size();j++){
                if(nums1[j] - tmp == nums2[cnt2]){
                    cnt++;
                    cnt2++;
                }
                if(cnt == nums2.size()){
                    return -tmp;
                }
            }
        }
        return 0;
    }
};