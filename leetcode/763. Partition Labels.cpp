class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> hash(26), ans;
        for (int i = 0; i < s.size(); i++) hash[s[i] - 'a'] = i;
        int left = 0, right = 0, maxIdx = 0;
        while (right < s.size()) {
            do maxIdx = max(maxIdx, hash[s[right++] - 'a']);
            while (right < s.size() and right <= maxIdx);
            ans.push_back(right - left);
            left = right;
        }
        return ans;
    }
};
