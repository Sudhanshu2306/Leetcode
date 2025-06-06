class Solution {
public:
    vector<int> count;
    char f(){
        for(int i=0;i<26;i++){
            if(count[i]!=0) return 'a'+i;
        }
        return 'a';
    }
    string robotWithString(string s) {
        count.resize(26,0);
        for(auto it:s) count[it-'a']++;
        stack<char> st;

        string ans="";
        for(auto it:s){
            st.push(it); count[it-'a']--;
            while(!st.empty() && st.top()<=f()){
                ans+=st.top(); st.pop();
            }
        }
        while(!st.empty()){
            ans+=st.top(); st.pop();
        }
        return ans;
    }
};