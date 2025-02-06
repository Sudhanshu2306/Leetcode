class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        map<int,int> mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                mp[nums[i]*nums[j]]++;
            }
        }
        int count=0;
        for(auto it:mp){
            if(it.second>=2){
                // nC2 = n*(n+1)/2;
                count+=(it.second*(it.second-1))/2;
            }
        }
        // 2 ways of placing each pair, and within themselves 2*2 ways of arranging, i.e 2*2*2=8 ways
        count*=8;
        return count;
    }
};