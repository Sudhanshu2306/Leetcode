class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> temp;
        deque<int> dq;

        for(int i=0;i<n;i++){
            if(!dq.empty() && nums[i]!=dq.back()+1) dq.clear();
            dq.push_back(nums[i]);

            if(dq.size()>k) dq.pop_front();

            if(dq.size()==k){
                temp.push_back(dq.back()); dq.pop_front();
            }
            else if(i>=(k-1)) temp.push_back(-1);
        }
        return temp;
    }
};