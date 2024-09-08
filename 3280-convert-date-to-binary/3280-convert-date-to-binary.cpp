class Solution {
public:
    string convertDateToBinary(string date) {
        int y=stoi(date.substr(0,4));
        int m=stoi(date.substr(5,2));
        int d=stoi(date.substr(8,2));

        string yy=bitset<12>(y).to_string(); yy=yy.substr(yy.find('1')); 
        string mm=bitset<12>(m).to_string(); mm=mm.substr(mm.find('1')); 
        string dd=bitset<12>(d).to_string(); dd=dd.substr(dd.find('1')); 

        return yy+"-"+mm+"-"+dd;
    }
};