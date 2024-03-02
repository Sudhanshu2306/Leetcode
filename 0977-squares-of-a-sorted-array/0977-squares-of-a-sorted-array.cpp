class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        priority_queue<long long> pq;
        int n=nums.size();
        for(int i=0;i<n;i++){
            pq.push((long long)nums[i]*nums[i]);
        }
        for(int i=n-1;i>=0;i--){
            nums[i]=pq.top();
            pq.pop();
        }
        return nums;
    }
};