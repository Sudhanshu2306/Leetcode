class Solution {
public:
    int countDays(int days, vector<vector<int>>& a) {
        sort(a.begin(),a.end());
        int n=a.size();

        int count=a[0][0]-1;
        int prev=a[0][1];
        for(int i=1;i<n;i++){
            if(a[i][0]>prev){
                count+=(a[i][0]-prev-1);
                prev=max(prev,a[i][1]);
            }
            else{
                prev=max(prev,a[i][1]);
            }
        }
        count+=days-prev;
        return count;
    }
};