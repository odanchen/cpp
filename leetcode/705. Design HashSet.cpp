class MyHashSet {
public:
    MyHashSet() : hashFunc(10000), table(hashFunc) {}
    
    void add(int key) {
        if (!contains(key)) table[key % hashFunc].push_back(key);
    }
    
    void remove(int key) {
        int hash = key % hashFunc;
        if (contains(key)) table[hash].erase(find(key));
    }
    
    bool contains(int key) {
        return find(key) != table[key % hashFunc].end();
    }
private:
    int hashFunc;
    
    vector<list<int>> table;
    
    list<int>::iterator find(int key) {
        return std::find(table[key % hashFunc].begin(), table[key % hashFunc].end(), key);
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
