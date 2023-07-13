class MyHashMap {
public:
    MyHashMap() : hashFunc(10000), table(hashFunc) {}
    
    void put(int key, int value) {
        if (!contains(key)) bucket(key)->push_back({key, value});
        else find(key)->second = value;
    }
    
    int get(int key) {
        return contains(key) ? find(key)->second : -1;
    }
    
    void remove(int key) {
        if (contains(key)) bucket(key)->erase(find(key));
    }
private:
    int hashFunc;
    
    vector<list<pair<int, int>>> table;
    
    vector<list<pair<int, int>>>::iterator bucket(int key) {
        return table.begin() + (key % hashFunc);
    }
    
    list<pair<int, int>>::iterator find(int key) {
        return find_if(bucket(key)->begin(), bucket(key)->end(), [&](pair<int, int> &a){return a.first == key;});
    }
    
    bool contains(int key) {
        return find(key) != bucket(key)->end();
    }
};


/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
