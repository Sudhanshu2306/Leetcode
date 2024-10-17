class Solution {
public:
    int maximumSwap(int num) {
        string s=to_string(num);
        int n=s.size();
        int i=0;

        for(int i=0;i<n;i++){
            int ind=i;
            for(int j=i+1;j<n;j++){
                if(s[ind]<=s[j]) ind=j;
            }
            if(s[i]<s[ind]){
                swap(s[i],s[ind]); return stoi(s);
            }
        }
        return num;
    }
};