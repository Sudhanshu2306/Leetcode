class Solution {
public:
    int maxBalancedShipments(vector<int>& a) {
        int count=0;
        int n=a.size();
        int maxi=a[0];
        int i=0;
        while(i<n){
            if(a[i]<maxi){
                count++; i++;
                if(i<n){
                    maxi=a[i]; i++;
                }
            }
            else{
                maxi=max(maxi,a[i]); i++;
            }
        }
        return count;
    }
};