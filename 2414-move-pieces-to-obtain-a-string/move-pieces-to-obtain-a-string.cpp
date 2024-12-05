class Solution {
public:
    bool canChange(string start, string target) {
        int n=start.size();
        int i=0,j=0;
        while(i<n || j<n){
            while(j<n && target[j]=='_') j++;
            while(i<n && start[i]=='_') i++;

            if(start[i]!=target[j]) return false;
            // target has more left blank spaces
            if(start[i]=='L' && i<j) return false;
            // target has more right blank spaces
            if(start[i]=='R' && i>j) return false;
            i++,j++;
        }
        return true;
    }
};