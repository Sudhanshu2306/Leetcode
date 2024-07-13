class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& pos, vector<int>& h, string d) {
        int n=d.size();
        vector<pair<int,int>> com;
        // to map postion to index as it it not in sorted order
        for(int i=0;i<pos.size();i++){
            com.push_back({pos[i],i});
        }
        sort(com.begin(),com.end());

        // stack mein index push kar rahe h
        stack<int> st;

        // collide ek se hi kar sakta h, 3-4 sath mein nahi karenge
        for(int i=0;i<n;i++){
            int ind=com[i].second;
            while(!st.empty() && h[ind]>0){
                // one imp case, hamesha opposite direction mein rehne se collide nahi hoga
                // agar pehle wala left jaa raha, aur dusre wala right toh bhi collision nahi hoga
                if(d[st.top()]==d[ind] || (d[ind]=='R' && d[st.top()]=='L')) break; 
                // case 1
                if(h[st.top()]>h[ind]){
                    h[ind]=0; 
                    h[st.top()]--;
                    ind=st.top(); st.pop(); 
                    break;
                }
                // case 2 : equality
                else if(h[st.top()]==h[ind]){
                    h[st.top()]=0;
                    h[ind]=0; st.pop();
                    break;
                }
                // case 3 
                else{
                    h[ind]--;
                    h[st.top()]=0;
                    st.pop();
                }
            }
            if(h[ind]) st.push(ind);
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(h[i]>0) ans.push_back(h[i]);
        }
        return ans;
    }
};
