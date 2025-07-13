class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& a, vector<int>& b) {
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());

        int i=0,j=0;
        int count=0;
        while(i<a.size() && j<b.size()){
            if(a[i]<=b[j]){
                count++;
                i++; j++;
            }
            else if(a[i]>b[j]){
                j++;
            }
        }
        return count;
    }
};