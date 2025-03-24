class Solution {
public:
    int countDays(int days, vector<vector<int>>& a) {
        sort(a.begin(),a.end());
        // for(auto it:a) cout<<it[0]<<" "<<it[1]<<endl;
        int count=a[0][0]-1;
        int e=a[0][1];
        for(int i=1;i<a.size();i++){
            if(a[i][0]<=e) e=max(e,a[i][1]);
            else{
                count+=(a[i][0]-e-1);
                e=max(e,a[i][1]);
            }
            cout<<e<<" ";
        }
        count+=(days-e);
        return count;
        // return 0;
    }
};