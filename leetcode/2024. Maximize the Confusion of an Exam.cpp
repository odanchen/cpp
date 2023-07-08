class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        vector<int> preFix(answerKey.size() + 1);
        for (int i = 1; i < preFix.size(); i++) preFix[i] = preFix[i - 1] + (answerKey[i - 1] == 'T' ? 1 : 0);
        int right = 0, tLeft = 0, fLeft = 0, ans = 0;
        while(right < answerKey.size()) {
            while(right - tLeft - preFix[right + 1] + preFix[tLeft] + 1 > k) tLeft++;
            while(preFix[right + 1] - preFix[fLeft] > k) fLeft++;
            right++;
            ans = max(ans, max(right - fLeft, right - tLeft));
        }
        return ans;
    }
};
