class Solution {
public:
    int maxFreeTime(int x, vector<int>& s, vector<int>& e) {
        sort(s.begin(),s.end());
        sort(e.begin(),e.end());
        int n=s.size();

        vector<int> gap; gap.push_back(s[0]); 
        for(int i=1;i<n;i++){
            gap.push_back(s[i]-e[i-1]);
        }
        gap.push_back(x-e[n-1]);

        vector<int> left(n+1,0), right(n+1,0);
        left[0]=s[0]; right[n]=x-e[n-1];
        for(int i=1;i<=n;i++){
            left[i]=max(left[i-1],gap[i]);
        }
        for(int i=n-1;i>=0;i--){
            right[i]=max(right[i+1],gap[i]);
        }
        int maxi=0;

        for(int i=0;i<n;i++){
            int len=e[i]-s[i];
            if(i>=1 && left[i-1]>=len || i<=n-2 && right[i+2]>=len) maxi=max(maxi,gap[i]+len+gap[i+1]);
            else maxi=max(maxi,gap[i]+gap[i+1]);
        }
        return maxi;
    }
};