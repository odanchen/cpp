class Solution {
public:
    typedef pair<int, int> line;
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        auto comp = [](line a, line b){return (a.second == b.second) ? a.first > b.first : a.second > b.second;};
        priority_queue<line, vector<line>, function<bool(line, line)>> ansQueue(comp);

        for (int i = 0; i < mat.size(); i++) {
            int left = 0, right = mat[i].size(), mid;
            while (left < right) {
                mid = (left + right) / 2;
                if (mat[i][mid] == 1) left = mid + 1;
                else right = mid;
            }
            ansQueue.push(line(i, left));
        }
        vector<int> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(ansQueue.top().first);
            ansQueue.pop();
        }
        return ans;
    }
};
