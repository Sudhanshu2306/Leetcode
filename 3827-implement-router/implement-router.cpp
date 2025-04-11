class Router {
public:
    int x=0;
    queue<vector<int>> q;
    set<vector<int>> st;
    unordered_map<int,vector<int>> tp;
    unordered_map<int,int> removed;
    Router(int memoryLimit) {
        x=memoryLimit;
    }
    
    bool addPacket(int s, int d, int t) {
        vector<int> a={s,d,t};
        if(st.find(a)!=st.end()) return false;

        if(q.size()==x){
            vector<int> ans=q.front();
            st.erase(ans); q.pop();
            removed[ans[1]]++;

        }
        q.push(a);
        tp[d].push_back(t);
        st.insert(a); return true;
    }
    
    vector<int> forwardPacket() {
        vector<int> ans;
        if(!q.empty()){
            ans=q.front(); q.pop();
            st.erase(ans);
            removed[ans[1]]++;
            return ans;
        }
        return ans;
    }
    
    int getCount(int d, int s, int e) {
        if(tp.find(d)==tp.end()) return 0;
        vector<int> &arr=tp[d];
        int r=removed[d];
        int a=lower_bound(arr.begin()+r,arr.end(),s)-arr.begin();
        int b=upper_bound(arr.begin()+r,arr.end(),e)-arr.begin();
        return b-a;
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */