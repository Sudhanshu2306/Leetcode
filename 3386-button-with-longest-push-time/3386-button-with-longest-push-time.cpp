class Solution {
public:
    int buttonWithLongestTime(vector<vector<int>>& events) {
        vector<int> time(1e6+1,0);
        int prev=0;
        int maxi=-1;
        for(auto it:events){
            time[it[0]]=max(time[it[0]],it[1]-prev);
            prev=it[1];
        }
        int ind=-1;
        for(int i=1;i<1e6+1;i++){
            if(maxi<time[i]){
                maxi=time[i]; ind=i;
            }
        }
        return ind;
    }
};