class Solution {
public:
    bool permute(string &s1, string &s2, string &s3, int idx1, int idx2, vector<vector<bool>> &visited) {
        if (idx1 + idx2 == s3.size()) return true;
        if (visited[idx1][idx2]) return false;
        visited[idx1][idx2] = true;
        if (s1[idx1] == s3[idx1 + idx2] and s2[idx2] != s3[idx1 + idx2])
            return permute(s1, s2, s3, idx1 + 1, idx2, visited);
        if (s1[idx1] != s3[idx1 + idx2] and s2[idx2] == s3[idx1 + idx2])
            return permute(s1, s2, s3, idx1, idx2 + 1, visited);
        if (s1[idx1] == s3[idx1 + idx2] and s2[idx2] == s3[idx1 + idx2])
            return permute(s1, s2, s3, idx1, idx2 + 1, visited) or permute(s1, s2, s3, idx1 + 1, idx2, visited);
        return false;
    }

    bool isInterleave(string s1, string s2, string s3) {
        if (s3.size() != s1.size() + s2.size()) return false;
        s1.push_back('/');
        s2.push_back('/');
        vector<vector<bool>> visited(s1.size(), vector<bool>(s2.size()));
        return permute(s1, s2, s3, 0, 0, visited);
    }
};
