class Solution {
public:
    bool equalFrequency(string word) {
        vector<int> arr(26,0);
        for(int i=0;i<word.size();i++){
            arr[word[i]-'a']++;
        }
        sort(arr.begin(),arr.end());

        int i=0;
        while(i<26 && arr[i]==0){
            i++;
        }

        if(i==25 || (arr[i]==1 && arr[i+1]==arr[25]) || (arr[i]==arr[24] && arr[25]==arr[24]+1)) return true;
        else return false;
    }
};