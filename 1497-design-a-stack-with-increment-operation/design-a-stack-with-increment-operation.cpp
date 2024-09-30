class CustomStack {
public:
    vector<int> arr;
    int s;
    CustomStack(int maxSize) {
        this->s=maxSize;
    }
    
    void push(int x) {
        if(arr.size()<s) arr.push_back(x);
        
    }
    
    int pop() {
        if(arr.empty()) return -1;
        else{
            int temp = arr.back();
            arr.pop_back();
            return temp;
        }
    }
    
    void increment(int k, int val) {
        for(int i=0;i<k && i<arr.size();i++) arr[i]+=val;
        
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */