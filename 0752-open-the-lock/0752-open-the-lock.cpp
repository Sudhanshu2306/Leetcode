class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> st;
        for(auto i:deadends) st.insert(i);

        if(st.find("0000")!=st.end()) return -1;
        queue<string> q;
        q.push("0000");

        int ans=0;
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                auto temp=q.front();
                q.pop();

                if(temp==target) return ans;

                for(int j=0;j<4;j++){
                    char ch=temp[j];

                    char x,y;
                    if(ch=='9') x='0';
                    else x=ch+1;

                    if(ch=='0') y='9';
                    else y=ch-1;

                    temp[j]=x;
                    if(st.find(temp)==st.end()){
                        st.insert(temp);
                        q.push(temp);
                    } 

                    temp[j]=y;
                    if(st.find(temp)==st.end()){
                        st.insert(temp);
                        q.push(temp);
                    }

                    temp[j]=ch;
                }
            }
            ans++;
        }
        return -1;
    }
};