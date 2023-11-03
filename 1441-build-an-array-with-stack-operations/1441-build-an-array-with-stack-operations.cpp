class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int j=0;
        int i=1;
        while(j<target.size() && i<=n ){
            if(target[j]==i){
                ans.push_back("Push");
                i++;
                j++;
                
            }
            else{
                ans.push_back("Push");
                ans.push_back("Pop");
                i++;
            }
        }
        return ans;
    }
};  