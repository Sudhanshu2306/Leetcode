class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int maxi=0;
        for(int i=0;i<32;i++){
            int count=0;
            for(auto it:candidates){
                if(it & (1<<i)) count++; // only if that number has a set bit at ith bit 
            }
            maxi=max(maxi,count);
        }
        return maxi;
    }
};