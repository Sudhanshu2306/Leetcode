class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, vector<int>> rem;
        for (int i = 0; i < arr.size(); i++) {
            int ireminder = arr[i] % k;
            if (ireminder < 0) 
                ireminder += k;
            rem[ireminder].push_back(arr[i]);
        }
        for(auto keyValue : rem) {
            int pairRem = (k - keyValue.first) % k;
           while (rem[keyValue.first].size() > 0) {
                if (keyValue.first == pairRem && rem[keyValue.first].size() < 2) {
                    return false; 
                }
                if (rem.find(pairRem) == rem.end() || rem[pairRem].size() < 1)
                    return false; 
                rem[pairRem].pop_back();
                rem[keyValue.first].pop_back();          
            }
        }
        return true;
    }
};