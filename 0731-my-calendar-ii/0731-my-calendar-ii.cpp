class MyCalendarTwo {
public:
    vector<pair<int,int>> a,b;
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        for(auto it:b){
            int s=it.first;
            int e=it.second;
            if(max(s,start)<min(e,end)) return false;
        }
        for(auto it:a){
            int s=it.first;
            int e=it.second;
            if(max(s,start)<min(e,end)) b.push_back({max(s,start),min(e,end)});
        }
        a.push_back({start,end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */