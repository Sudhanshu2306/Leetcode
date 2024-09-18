class Solution {
public:
    bool comp(string a,string b){
        return a+b>b+a;
    }
    string largestNumber(vector<int>& nums) {
        string ans="";
        vector<string> x;
        for(int i=0;i<nums.size();i++){
            string y=to_string(nums[i]);
            x.push_back(y);
        }
        sort(x.begin(),x.end(),[&](string a,string b){
            return a+b>b+a;
        });
        for(auto i:x){
            ans+=i;
        }
        if(ans[0]=='0') return "0";
        return ans;
    }
};