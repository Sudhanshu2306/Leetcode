class Solution {
public:
    string largestTimeFromDigits(vector<int>& a){
        sort(a.rbegin(),a.rend());
        do if((a[0]<2 || (a[0]==2 && a[1]<=3)) && a[2]<6){
            return to_string(a[0])+to_string(a[1])+":"+to_string(a[2])+to_string(a[3]);
        }
        while(prev_permutation(begin(a),end(a)));
        return "";
    }
};