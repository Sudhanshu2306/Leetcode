class RandomizedSet {
public:
    
    vector<int> arr;
    unordered_map<int,int> mp;
    RandomizedSet() {
        // default constructor 
    }
    
    bool insert(int val) {
        if(mp.find(val)!=mp.end()) return false;
        arr.push_back(val);
        mp[val]=arr.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(mp.find(val)==mp.end()) return false;
        
        auto i=mp.find(val);
        arr[i->second] = arr.back(); arr.pop_back();
        mp[arr[i->second]]=i->second;
        mp.erase(val); return true;
    }
    
    int getRandom() {
        // rand returns random value between 0 to 1, 1 exclusive
        int ind = rand()%arr.size();
        return arr[ind];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */