class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int m=l.size();
        vector<bool> ans;
        for(int i=0;i<m;i++){
            vector<int> res;
            for(int j=l[i];j<=r[i];j++){
                res.push_back(nums[j]);
            }
            int d;
            sort(res.begin(),res.end());
            for(int i=1;i<res.size();i++){
                if(i==1){
                    d=res[i]-res[i-1];
                }
                else if(d!=(res[i]-res[i-1])) {
                    ans.push_back(false);
                    break;
                }
                if(i+1==res.size()){
                    ans.push_back(true);
                }
            }
        }
        return ans;
    }
};