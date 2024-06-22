class Solution {
public:
    // /*
    int f(vector<int>& nums, int k){
        int odd=0;
        int n=nums.size();
        
        int count=0;
        int i=0,j=0;
        while(j<n){
            if(nums[j]%2==1) odd++;
            while(i<=j && k<odd) 
                if(nums[i++]%2==1) odd--;

            count+=(j-i+1);
            j++;
        }
        return count;
    }
    // */
    int numberOfSubarrays(vector<int>& nums, int k) {
        return f(nums,k)-f(nums,k-1);
    }
};