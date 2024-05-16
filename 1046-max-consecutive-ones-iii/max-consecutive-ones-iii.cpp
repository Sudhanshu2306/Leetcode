class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int maxi=0;
        int zero=0;
        priority_queue<int, vector<int>, greater<int>> pq;

        int i=0,j=0;
        // simple sa logic h, k 0's ko 1 banana h, ab isko aaise dekho ki maximum sub-array with k zeros
        while(j<n){
            if(nums[j]==0){
                zero++;
                pq.push(j);
            } 
            if(zero<=k) maxi=max(maxi,j-i+1);
            else{
                i=pq.top()+1;
                pq.pop();
                zero--;
            }
            j++;
        }
        return maxi;
    }
};