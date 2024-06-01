class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indDiff, int valueDiff) {
        int n=nums.size();
        int x=-1,y=-1;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(abs(i-j)>=indDiff && abs(nums[i]-nums[j])>=valueDiff){
                    x=i;
                    y=j;
                    break;
                }
            }
        }
        return {x,y};
    }
};