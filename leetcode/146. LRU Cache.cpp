class LRUCache {
public:
    LRUCache(int capacity) : capacity(capacity), size(0) {}
    
    int get(int key) {
        auto it = itMap.find(key);
        if (it == itMap.end()) return -1;
        elements.splice(elements.begin(), elements, it->second);
        return elements.front().second;
    }
    
    void put(int key, int value) {
        auto it = itMap.find(key);
        if (it != itMap.end()) {
            it->second->second = value;
            elements.splice(elements.begin(), elements, it->second);
        } else {
            if (size < capacity) size++;
            else {
                itMap.erase(itMap.find(elements.back().first));
                elements.pop_back();
            }
            elements.push_front({key, value});
            itMap[key] = elements.begin();
        }
    }
private:
    int capacity;
    
    int size;

    list<pair<int, int>> elements;

    unordered_map<int, list<pair<int, int>>::iterator> itMap;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
