class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> mapi;
        for(int i = 0; i < arr2.size(); i++){
            mapi[arr2[i]] = i;
        }
        sort(arr1.begin(), arr1.end(), [&mapi](int i, int j) {
            int a = mapi.count(i) ? mapi[i] : -1;
            int b = mapi.count(j) ? mapi[j] : -1;

            if(a == -1 && b == -1) {
                return i < j;
            }
            if(a >= 0 && b >= 0) {
                return a < b;
            }
            return a >= 0;
        });
        return arr1;
    }
};