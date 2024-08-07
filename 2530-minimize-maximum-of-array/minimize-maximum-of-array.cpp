class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        double x=0;
        double y=0;
        for(int i=0;i<nums.size();i++){
            y+=nums[i];
            int avg=ceil(y/(i+1));
            if(x<=avg) x=avg;
        }
        return (int)x;
    }
};