class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n=s.size();
        int count=0;
        int cost=0;
        int i=0,j=0;
        while(j<n){
            cost+=abs(s[j]-t[j]);
            j++;
            while(cost>maxCost) {
                cost-=abs(s[i]-t[i]);
                i++;
            }
            count=max(count,j-i);
        }
        return count;
    }
};