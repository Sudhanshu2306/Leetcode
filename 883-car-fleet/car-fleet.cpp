class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n=speed.size();
        vector<pair<int,int>> hash(n);
        for(int i=0;i<n;i++){
            hash[i].first=position[i];
            hash[i].second=speed[i];
        }
        //gets sorted by according to distance
        sort(hash.begin(),hash.end());
        
        stack<double> st;
        for(int i=n-1;i>=0;i--){
            double t=((target-hash[i].first)*1.0)/hash[i].second;
            if(!st.empty() && st.top()>=t){
                continue;
            }
            st.push(t);
        }
        return st.size();
    }
    
};