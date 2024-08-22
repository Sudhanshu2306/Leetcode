class Solution {
public:
    int minProcessingTime(vector<int>& pt, vector<int>& tasks) {
        sort(tasks.begin(),tasks.end());
        sort(pt.rbegin(),pt.rend());

        int maxi=-1e9;
        int n=tasks.size();
        int i=0;
        int m=pt.size(); int k=0;
        while(i<n-4+1){
            int x=pt[k];
            x+=tasks[i+4-1];
            maxi=max(maxi,x);
            i+=4;
            k++;
        }
        return maxi;
    }
};