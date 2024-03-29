#include <string>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        stack<char> st;

        // Iterate through the string
        for (int i = 0; i < n; i++) {
            if (s[i] != ' ') {
                st.push(s[i]);
            } else {
                if (!st.empty() && st.top() != ' ') {
                    st.push(' '); 
                }
            }
        }

        string ans = "";
        string temp = "";

        while (!st.empty()) {
            if (st.top() != ' ') {
                temp += st.top();
            } else {
                if (!temp.empty()) { 
                    reverse(temp.begin(), temp.end()); 
                    ans += temp; 
                    ans += ' '; 
                    temp = ""; 
                }
            }
            st.pop();
        }
        if (!temp.empty()) {
            reverse(temp.begin(), temp.end());
            ans += temp;
        }

        while (!ans.empty() && ans.back() == ' ') {
            ans.pop_back();
        }
        return ans;
    }
};
