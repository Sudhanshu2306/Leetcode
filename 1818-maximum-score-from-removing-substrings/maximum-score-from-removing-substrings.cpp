class Solution {
public:
    int f(string &s,string temp){
        int n=s.size();
        stack<char> st;

        int score=0; int ans=0;
        for(int i=0;i<n;i++){
            if(!st.empty() && s[i]==temp[1] && st.top()==temp[0]){
                st.pop(); score++;
            } 
            else st.push(s[i]);
        }
        // cout<<score<<" ";
        s="";
        while(!st.empty()){
            s+=st.top(); st.pop();
        }
        reverse(s.begin(),s.end());

        return score;
    }

    int maximumGain(string s, int x, int y) {
        string mini, maxi;
        if(x>y){
            mini="ba";
            maxi="ab";
        }
        else{
            mini="ab";
            maxi="ba";
            swap(x,y);
        }
        int a=f(s,maxi)*x;
        int b=f(s,mini)*y;
        return a+b;
    }
};