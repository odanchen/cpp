class Solution {
public:
    template<typename Iterator>
    vector<int> fillBoxes(Iterator front, Iterator back) {
        int cnt = 0;
        vector<int> ans;
        while (front != back) {
            ans.push_back((ans.empty() ? 0 : ans.back()) + cnt);
            cnt += *(front++) == '1';
        }
        return ans;
    }

    vector<int> minOperations(string boxes) {
        vector<int> leftBoxes = fillBoxes(boxes.begin(), boxes.end());
        vector<int> rightBoxes = fillBoxes(boxes.rbegin(), boxes.rend());
        vector<int> ans(boxes.size());
        for (int i = 0; i < ans.size(); i++) ans[i] = leftBoxes[i] + rightBoxes[ans.size() - i - 1];
        return ans;
    }
};
