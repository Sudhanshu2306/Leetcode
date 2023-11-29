class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int n=nums.size();
        if(n==0){
            return ans;
        }
        int f=nums[0];
        int s=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]==s+1){
                s=nums[i];
            }
            else{
                string str="";
                str+=to_string(f);
                if(f!=s){
                    str+="->";
                    str+=to_string(s);
                }
                ans.push_back(str);
                f=nums[i];
                s=nums[i];
            }
        }
        string str="";
        str+=to_string(f);
        if(f!=s){
            str+="->";
            str+=to_string(s);
        }
        ans.push_back(str);
        return ans;
        
    }
};