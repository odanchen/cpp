class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for (vector<int> &line: image) {
            reverse(line.begin(), line.end());
            for (int &val: line) val = !val;
        }
        return image;
    }
};
