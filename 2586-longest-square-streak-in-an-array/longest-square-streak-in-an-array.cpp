class Solution {
public:
    int findPerfectSquare(int x){
        for(int i=1;i*i<=x;i++){
            if(i*i==x) return i;
        }
        return -1;
    }
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        unordered_map<int,int> mpp;
        int len=-1;
        for(int i=0;i<nums.size();i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int sr=findPerfectSquare(nums[i]);
            if(mpp.find(sr)!=mpp.end()){
                mpp[nums[i]]=mpp[sr]+1;
                len=max(len,mpp[nums[i]]);
            }
            else{
                mpp[nums[i]]++;
            }
        }
        return len;
    }
};
