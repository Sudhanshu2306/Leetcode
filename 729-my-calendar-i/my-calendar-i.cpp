class MyCalendar {
public:
    map<int,int> mp;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for(auto it:mp){
            int bs=it.first;
            int be=it.second;

            if(start<be && end>bs) return false;
        }
        mp[start]=end;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */