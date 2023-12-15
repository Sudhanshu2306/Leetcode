class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> a;
        for(auto i:paths){
            a.insert(i[0]);
        }
        for(auto i:paths){
            string d=i[1];
            if (a.find(d) == a.end()) {
                return d;
            }
        }
        return "";
    }
};