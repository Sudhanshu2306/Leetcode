class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int count=0;
        // int n=arr.size();
        for(auto i:arr){
            if(i&1){
                count++;
                if(count==3) return true;
            }
            else count=0;
        }
        return false;
    }
};