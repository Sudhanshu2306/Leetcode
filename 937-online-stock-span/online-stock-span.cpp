class StockSpanner {
public:
    stack<pair<int,int>> st;
    int i;
    StockSpanner() {
        i=1;
    }
    
    int next(int price) {
        while(!st.empty() && st.top().first<=price){ 
            st.pop();
        }
        int x=0;
        if(!st.empty()) x=st.top().second;
        st.push({price,i});
        int j=i;
        i++;
        return j-x;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */