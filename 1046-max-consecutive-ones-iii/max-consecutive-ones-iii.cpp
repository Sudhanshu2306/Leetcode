class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int maxi=0;
        int zero=0;
        // priority_queue<int, vector<int>, greater<int>> pq;
        queue<int> q;

        int i=0,j=0;
        // simple sa logic h, k 0's ko 1 banana h, ab isko aaise dekho ki maximum sub-array sum with k zeros
        while(j<n){
            if(nums[j]==0){
                zero++;
                q.push(j);
            } 
            if(zero<=k) maxi=max(maxi,j-i+1);
            else{
                i=q.front()+1;
                q.pop();
                zero--;
            }
            j++;
        }
        return maxi;
    }
};