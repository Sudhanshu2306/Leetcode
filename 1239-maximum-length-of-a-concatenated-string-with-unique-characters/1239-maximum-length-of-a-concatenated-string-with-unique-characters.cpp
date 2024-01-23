class Solution {
public:

    int f(int ind, unordered_set<char> st, vector<string> &arr){
        if(ind>=arr.size()) return 0;

        int notpick=f(ind+1,st,arr);
        int flag=1;
        for(auto i:arr[ind]){
            if(st.find(i)!=st.end()){
                flag=0; break;
            }
            else{
                st.insert(i);
            }
        }
        int pick=0;
        if(flag) pick= arr[ind].length() + f(ind+1,st,arr);
        
        return static_cast<int>(max(pick,notpick));
    }

    int maxLength(vector<string>& arr) {
        unordered_set<char> st;
        int n=arr.size();
        return f(0,st,arr);
    }
};