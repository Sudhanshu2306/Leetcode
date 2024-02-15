class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int i=0,j=n/2;
        int count=0;
        if(n%2==0){
            while(j<nums.size()){
                if((2*nums[i])<=nums[j]){
                    count+=2;
                    i++;
                } 
                j++;
            }
        }
        else{
            j+=1;
            while(j<nums.size()){
                if((2*nums[i])<=nums[j]){
                    count+=2;
                    i++;
                } 
                j++;
            }
        }
        return count;
    }
};