class OrderedStream {
public:
    OrderedStream(int n) : vec(n), idx(0) {}
    
    vector<string> insert(int idKey, string value) {
        vec[idKey - 1] = value;
        vector<string> ans;
        while (idx < vec.size() and !vec[idx].empty()) ans.push_back(vec[idx++]);
        return ans;
    }
    vector<string> vec;
    int idx;
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */
