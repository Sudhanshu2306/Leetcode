class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        vector<int> temp;
        int n=colors.size();
        for(int i=0;i<n;i++) temp.push_back(colors[i]);

        for(int j=0;j<k-1;j++) temp.push_back(colors[j]);

        int count=0;
        int m=temp.size();
        int i=0;
        for(int j=0;j<m;j++){
            if(j>0 && temp[j]==temp[j-1]) i=j;
            if(j-i+1>=k) count++;
        }
        return count;
    }
};