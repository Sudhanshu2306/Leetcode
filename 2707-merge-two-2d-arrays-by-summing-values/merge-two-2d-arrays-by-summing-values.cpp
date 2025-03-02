class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& a, vector<vector<int>>& b) {
        vector<vector<int>> ans;
        int i=0,j=0;

        while(i<a.size() && j<b.size()){
            if(a[i][0]==b[j][0]){
                ans.push_back({a[i][0],a[i][1]+b[j][1]}); i++; j++;
            }
            else if(a[i][0]>b[j][0]){
                ans.push_back({b[j][0],b[j][1]}); j++;
            }
            else{
                ans.push_back({a[i][0],a[i][1]}); i++;
            }
        }
        while(i<a.size()){
            ans.push_back({a[i][0],a[i][1]}); i++;
        }
        while(j<b.size()){
            ans.push_back({b[j][0],b[j][1]}); j++;
        }
        return ans;
    }
};