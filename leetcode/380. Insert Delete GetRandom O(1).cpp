class RandomizedSet {
public:
    vector<int> vals;
    unordered_map<int, int> valMap;

    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (valMap.find(val) != valMap.end()) return false;
        valMap.insert({val, vals.size()});
        vals.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if (valMap.find(val) == valMap.end()) return false;
        swap(valMap[vals.back()], valMap[val]);
        swap(*vals.rbegin(), vals[valMap[vals.back()]]);
        vals.pop_back();
        valMap.erase(val);
        return true;
    }
    
    int getRandom() {
        return vals[rand() % vals.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
