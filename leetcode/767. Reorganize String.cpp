class Solution {
public:
    string reorganizeString(string s) {
        string ans;
        ans.reserve(s.size());
        vector<int> chars(26);
        priority_queue<pair<int, char>> q;
        for (char c: s) chars[c - 'a']++;
        for (int i = 0; i < chars.size(); i++) if (chars[i] != 0) q.emplace(chars[i], i + 'a');
        while (ans.size() < s.size()) {
            auto top = q.top();
            q.pop();
            if (ans.empty() or top.second != ans.back()) {
                ans.push_back(top.second);
                if (top.first > 1) q.emplace(top.first - 1, top.second);
            } else {
                if (q.empty()) return "";
                auto temp = q.top();
                q.pop();
                ans.push_back(temp.second);
                if (temp.first > 1) q.emplace(temp.first - 1, temp.second);
                if (top.first > 0) q.emplace(top.first, top.second);
            }
        }
        return ans;
    }
};
