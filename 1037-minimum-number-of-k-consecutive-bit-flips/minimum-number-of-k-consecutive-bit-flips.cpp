class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n=nums.size();
        int count=0;
        queue<int> q;

        for(int i=0;i<n;i++){
            while(!q.empty() && i>q.front()+k-1) q.pop();
            if((nums[i]+q.size())%2==0){
                if(i+k>n) return -1;
                count+=1;
                q.push(i);
            }
        }
        return count;
    }
};