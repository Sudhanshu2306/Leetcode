class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=haystack.size();
        int m=needle.size();
        int index=0;
        for(int i=0;i<n;i++){
            if(haystack.at(i)==needle.at(index)){
                index++;
            }
            else{
                i=i-index;
                index=0;
            }
            if(index==m){
                return i-m+1;
            }
        }
        return -1;
    }
};