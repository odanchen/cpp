class Solution {
public:
    int countPoints(string rings) {
        vector<vector<bool>> check(10, vector<bool>(3));
        unordered_map<char, int> color = {{'R', 0}, {'G', 1}, {'B', 2}};
        for (int i = 0; i < rings.size(); i += 2) {
            check[rings[i + 1] - '0'][color[rings[i]]] = true;
        }
        return count_if(check.begin(), check.end(), [](vector<bool> &a){return a[0] && a[1] && a[2];});
    }
};
