class MyHashMap {
public:
    vector<int> hash;
    MyHashMap() {
        for(int i=0;i<1e6+1;i++)
        {
            hash.push_back(-1);
        }
    }
    
    void put(int key, int value) {
        this->hash[key]=value;
    }
    
    int get(int key) {
        return this->hash[key];
    }
    
    void remove(int key) {
       this->hash[key]=-1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */