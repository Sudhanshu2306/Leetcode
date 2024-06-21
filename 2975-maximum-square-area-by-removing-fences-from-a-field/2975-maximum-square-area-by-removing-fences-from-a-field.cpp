class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        hFences.push_back(1); vFences.push_back(1);
        hFences.push_back(m); vFences.push_back(n);

        unordered_set<int> st;
        for(int i=0;i<hFences.size();i++){
            for(int j=i+1;j<hFences.size();j++){
                st.insert(abs(hFences[i]-hFences[j]));
            }
        }

        long long maxi=-1;
        for(int i=0;i<vFences.size();i++){
            for(int j=i+1;j<vFences.size();j++){
                int side=abs(vFences[i]-vFences[j]);
                if(st.find(side)!=st.end()) maxi=max(maxi,(long long)side);
            }
        }
        if(maxi==-1) return -1;
        else{
            long long mod=1e9+7;
            long long ans=(maxi*maxi)%mod;
            return (int)ans;
        } 

    }
};