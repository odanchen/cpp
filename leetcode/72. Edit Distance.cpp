class Solution {
public:
    int permute(string &word1, string &word2, vector<vector<int>> &visited, int cur, int idx1, int idx2) {
        if (idx1 >= word1.size() or idx2 >= word2.size()) return word1.size() + word2.size() - idx1 - idx2 + cur;
        if (visited[idx1][idx2] != -1 and cur >= visited[idx1][idx2]) return INT_MAX;
        if (word1[idx1] == word2[idx2]) {
            visited[idx1][idx2] = cur;
            return permute(word1, word2, visited, cur, idx1 + 1, idx2 + 1);
        } else {
            if (visited[idx1][idx2] == cur + 1) return INT_MAX;
            visited[idx1][idx2] = cur + 1;
            return min(permute(word1, word2, visited, cur + 1, idx1 + 1, idx2 + 1),
                    min(permute(word1, word2, visited, cur + 1, idx1, idx2 + 1),
                        permute(word1, word2, visited, cur + 1, idx1 + 1, idx2)));
        }

    }

    int minDistance(string word1, string word2) {
        vector<vector<int>> visited(word1.size(), vector<int>(word2.size(), -1));
        return permute(word1, word2, visited, 0, 0, 0);
    }
};
