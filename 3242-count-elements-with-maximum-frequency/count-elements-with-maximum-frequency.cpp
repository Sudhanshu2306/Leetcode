class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> a(101,0);
        int maxi=0;
        for(auto i:nums){
            a[i]++;
            maxi=max(maxi,a[i]);
        }
        int count=0;
        for(auto i:a){
            if(i==maxi) count++;
        }
        return count*maxi;
    }
};