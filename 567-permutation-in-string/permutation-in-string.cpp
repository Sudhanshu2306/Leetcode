class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s1.size();
        map<char,int> mp;
        for(auto i:s1) mp[i]++;

        int m=s2.length();
        if(m<n) return false;
        map<char,int> mp2;
        for(int i=0;i<n;i++){
            mp2[s2[i]]++;
        }
        int i=0,j=n-1;
        while(j<m){
            if(mp2==mp) return true;
            else{
                mp2[s2[i]]--;
                if(mp2[s2[i]]==0) mp2.erase(s2[i]);
                i++;
                if(j+1<m)mp2[s2[j+1]]++;
                if(mp2==mp) return true;
            }
            j++;
        }
        return false;
    }
};