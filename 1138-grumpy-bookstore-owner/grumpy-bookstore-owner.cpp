class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n=grumpy.size();
        int sum=0;
        int x=minutes;
        for(int i=0;i<n;i++){
            if(grumpy[i]==0) sum+=customers[i];
            if(x>0 && grumpy[i]==1) sum+=customers[i];
            x--;
        }
        
        int maxi=sum;
        for(int i=minutes;i<n;i++){
            if(grumpy[i-minutes]==1) sum-=customers[i-minutes];
            if(grumpy[i]==1) sum+=customers[i];
            maxi=max(maxi,sum);
        }
        return maxi;

    }
};