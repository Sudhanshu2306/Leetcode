class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int n=words.size();
        map<char,int> mp;
        for(int i=0;i<order.size();i++){
            mp[order[i]]=i;
        }
        bool flag=1, f=0;
        for(int i=0;i<n-1;i++){
            string a=words[i];
            string b=words[i+1];
            int x=0;
            while(x<a.size() && x<b.size()){
                // cout<<mp[a[x]]<<" "<<mp[b[x]]<<endl;
                if(mp[a[x]]<mp[b[x]]){
                    f=1;
                    flag=1; break;
                }
                else if(mp[a[x]]>mp[b[x]]){
                    flag=0;
                    break;
                } 
                else{
                    
                }
                x++;
            }
            if(x<a.size() && f==0){
                flag=0;
            } 
            if(flag==0) break;
            f=0;
        }
        return flag==1?true:false;
    }
};