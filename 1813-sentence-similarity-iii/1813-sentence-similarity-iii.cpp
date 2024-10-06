class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        int i1=0, i2=0;
        // if s1 has just one word and it is same, then it could be first or last
        // if there are more words, it is a combination of words in order from 
        // start and from last, not some from middle
        // bas yahi concept h, aur two pointers h baaki implementation
        if(s1==s2) return true;
        vector<string> a,b;
        
        while(i1<s1.size()){
            string temp="";
            while(s1[i1]!=' ' && i1<s1.size()){
                temp+=s1[i1]; i1++;
            }
            a.push_back(temp); i1++;
        }
        while(i2<s2.size()){
            string temp="";
            while(s2[i2]!=' ' && i2<s2.size()){
                temp+=s2[i2]; i2++;
            }
            b.push_back(temp); i2++;
        }
        if(a.size()>b.size()){
            swap(a,b);
        }
        int i=0, j1=a.size()-1,j2=b.size()-1;
        while(i<a.size() && a[i]==b[i]) i++;
        while(j1>=0 && a[j1]==b[j2]){
            j1--,j2--;
        }
        if(j1<i) return true;
        return false;
    }
};