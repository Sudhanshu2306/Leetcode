class Solution {
public:
    int f(string &s, string t){
        stack<char> st;
        int count=0;
        for(int i=0;i<s.size();i++){
            if(!st.empty() && st.top()==t[0] && s[i]==t[1]){
                count++; st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        s="";
        while(!st.empty()){ 
            s+=st.top(); st.pop();
        }
        reverse(s.begin(),s.end());
        return count;
    }
    int maximumGain(string s, int x, int y) {
        if(x>y){
            int a=f(s,"ab")*x;
            int b=f(s,"ba")*y;
            return a+b;
        }
        else{
            int a=f(s,"ba")*y;
            int b=f(s,"ab")*x;
            return a+b;
        }
    }
};