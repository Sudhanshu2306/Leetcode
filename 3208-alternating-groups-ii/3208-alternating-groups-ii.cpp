class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        vector<int> temp;
        int n=colors.size();
        for(int i=0;i<n;i++) temp.push_back(colors[i]);

        for(int j=0;j<k-1;j++) temp.push_back(colors[j]);

        int count = 0;
        int m=temp.size();

        for(int i=0;i<m;i++) {
            int x=1;
            // cout<<count<<" ";
            for(int j=i+1;j<m;j++){
                if(temp[j] != temp[j-1]) x++;

                else{
                    // cout<<i<<" ";
                    i=j-1;
                    break;
                }

                if(j==m-1){
                    i=3*m;
                    break;
                }
            }
            // cout<<count<<" ";
            count+=max(0,x+1-k);
            // cout<<count<<" ";
        }
        return count;
    }
};