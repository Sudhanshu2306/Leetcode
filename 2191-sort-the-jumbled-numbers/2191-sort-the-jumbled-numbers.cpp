class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,int>> mp;
        for(int i=0;i<n;i++){
            int num=nums[i];
            int newNum=num==0?mapping[0]:0;
            int exp=1;
            while(num) {
                int digit=num%10;
                newNum+=exp*mapping[digit];
                num/=10;
                exp*=10;
            }
            mp.push_back({newNum,i});
        }
        sort(mp.begin(),mp.end());
        vector<int> temp;
        for(auto i:mp){
            temp.push_back(nums[i.second]);
        }
        return temp;
    }
};