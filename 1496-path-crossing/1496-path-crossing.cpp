class Solution {
public:
    bool isPathCrossing(string path) {
        int x=0,y=0;
        unordered_set<string> ans;
        ans.insert(to_string(x)+"-"+to_string(y));
        for(int i=0;i<path.length();i++){
            if(path[i]=='N'){
                y++;
            }
            if(path[i]=='S'){
                y--;
            }
            if(path[i]=='E'){
                x++;
            }
            if(path[i]=='W'){
                x--;
            }
            string res=(to_string(x)+"-"+to_string(y));
            if(ans.find(res)!=ans.end()){
                return true;
            }
            else{
                ans.insert(res);
            }
             
        }
        return false;
    }
};