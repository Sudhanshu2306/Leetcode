class MyCalendarThree {
public:
    map<int,int> mp;
    int count=0;
    MyCalendarThree() {
        
    }
    
    int book(int startTime, int endTime) {
        mp[startTime]++;
        mp[endTime]--;
        int x=0;
        for(auto it:mp){
            x+=it.second;
            count=max(count,x);
        }
        return count;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */