class Spreadsheet {
public:
    vector<vector<int>> a;
    Spreadsheet(int rows) {
        a.resize(rows+1,vector<int>(26,0));
    }
    
    void setCell(string cell, int value) {
        int c=cell[0]-'A';
        int r=stoi(cell.substr(1));
        a[r][c]=value;
    }
    
    void resetCell(string cell) {
        int c=cell[0]-'A';
        int r=stoi(cell.substr(1));
        a[r][c]=0;
    }
    int f(string s){
        if(isdigit(s[0])) return stoi(s);
        int c=s[0]-'A';
        int r=stoi(s.substr(1));
        return a[r][c];
    }
    int getValue(string formula) {
        int plus=formula.find('+');

        return f(formula.substr(1,plus))+f(formula.substr(plus+1));
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */