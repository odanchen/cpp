class Solution {
public:
    vector<int> processQueries(vector<int> &queries, int m) {
        vector<int> vec(m), ans;
        for (int i = 0; i < m; i++) vec[i] = i + 1;
        for (int val: queries) {
            int idx = 0;
            for (int i = 0; i < vec.size(); i++) {
                if (vec[i] == val) {
                    idx = i;
                    break;
                }
            }
            ans.push_back(idx);
            vec.erase(vec.begin() + idx);
            vec.insert(vec.begin(), val);
        }
        return ans;
    }
};
