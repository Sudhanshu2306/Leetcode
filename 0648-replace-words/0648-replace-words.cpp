class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        stringstream ss(sentence);
        string token;
        vector<string> sent;
        char delimiter = ' ';
        while( getline(ss,token,delimiter)){
            sent.push_back(token);
        }
        
        string ans="";
        for(int i =0 ;i < sent.size(); i++){
          string word = sent[i];
          
          bool flag = 1;
          string s ="";
          int minidx = INT_MAX;
          for(auto &str : dictionary){
            int idx = 0;
            flag = 1;
            
            
            while(idx < str.size()){
                if(str.size() > word.size()){
                    flag = 0;
                    break;
                }
              if(word[idx] != str[idx]){
                flag = 0;
                break;
              }
              idx++; 
            }
            
             if( flag && minidx > str.size()){
                minidx = str.size();
                s = str;
            }
          }
          if( s.size() == 0)ans += word;
          else ans += s;
         
          if(i < sent.size()-1)ans += " ";
        }
        return ans;
    }
};