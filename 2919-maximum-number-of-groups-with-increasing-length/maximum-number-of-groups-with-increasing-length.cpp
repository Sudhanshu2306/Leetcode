class Solution {
public:
    int maxIncreasingGroups(vector<int>& ul) {
        int n=ul.size();
        sort(ul.begin(),ul.end());

        int count=0;
        long long sum=0;
        long long x=0;
        for(int i=0;i<n;i++){
            sum+=ul[i];
            x=sum;
            if(x>=(count+1)){
                x-=(count+1);
                count++;
                sum=x;
            }
        }
        return count;
    }
};