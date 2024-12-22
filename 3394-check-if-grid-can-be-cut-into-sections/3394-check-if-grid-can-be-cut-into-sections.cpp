class Solution {
public:
    int ff(vector<vector<int>> &a){
        sort(a.begin(),a.end());
        int s=a[0][0]; int e=a[0][1];
        int count=0;
        for(int i=1;i<a.size();i++){
            if(e<=a[i][0]) count++;
            e=max(e,a[i][1]);
        }
        return count;
    }
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>> x,y;
        for(auto it:rectangles){
            x.push_back({it[0],it[2]});
            y.push_back({it[1],it[3]});
        }
        return ff(x)>=2 || ff(y)>=2;
    }
};