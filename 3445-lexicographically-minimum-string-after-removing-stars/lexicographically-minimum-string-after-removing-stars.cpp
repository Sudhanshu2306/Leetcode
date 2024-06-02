class Solution {
public:
    string clearStars(string s) {
        stack<char> st;
        string ans="";

        for(int i=0;i<s.size();i++){
            if(s[i]!='*'){
                ans.push_back(s[i]);
            }
            else{
                int ind=-1;
                char ch='z'+1;
                for(int j=ans.size()-1;j>=0;j--){
                    if(ans[j]<ch) {
                        ch=ans[j];
                        ind=j;
                    }
                    // else if(ans[j]>ch) break;
                }
                
                if(ind!=-1){
                    ans.erase(ans.begin()+ind);
                }
            } 
            
        }
        // reverse(ans.begin(),ans.end());
        return ans;
    }
};