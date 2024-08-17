class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> temp;
        queue<int> q;

        int i=0,j=0;
        if(k==1) return nums;

        for(int i=0;i<k-1;i++){
            if(nums[i]+1==nums[i+1]){}
            else q.push(i);
        }

        if(q.empty()) temp.push_back(nums[k-1]);
        else temp.push_back(-1);

        j=k-1;
        while(j<n-1){
            i++;
            if(!q.empty() && q.front()<i) q.pop();
            if(nums[j]+1==nums[j+1] && q.empty()) temp.push_back(nums[j+1]);
            else{
                temp.push_back(-1);
                if(nums[j]+1!=nums[j+1]) q.push(j);
            }
            j++;
        }
        return temp;
    }
};