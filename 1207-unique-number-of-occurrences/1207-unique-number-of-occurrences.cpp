class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_set<int> st1;
        unordered_set<int> st2;
        for(int i=0;i<arr.size();i++){
            st1.insert(arr[i]);
        }
        int count=1;
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size()-1;i++){
            if(arr[i]==arr[i+1]) count++;
            else{
                st2.insert(count);
                count=1;
            }
        }
        st2.insert(count);
        if(st1.size()==st2.size()) return true;
        else return false;
        
    }
};