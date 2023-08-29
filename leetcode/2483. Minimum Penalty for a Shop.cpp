class Solution {
public:
    int bestClosingTime(string customers) {
        vector<int> leftPenalty(customers.size()), rightPenalty(customers.size());
        leftPenalty[0] = customers[0] == 'N';
        rightPenalty.back() = customers.back() == 'Y';
        for (int i = 1; i < customers.size(); i++) {
            leftPenalty[i] = leftPenalty[i - 1] + (customers[i] == 'N');
        }
        for (int i = customers.size() - 2; i >= 0; i--) {
            rightPenalty[i] = rightPenalty[i + 1] + (customers[i] == 'Y');
        }
        int ans = 0, penalty = rightPenalty.front();
        for (int i = 1; i < customers.size(); i++) {
            if (penalty > leftPenalty[i - 1] + rightPenalty[i]) {
                ans = i;
                penalty = leftPenalty[i - 1] + rightPenalty[i];
            }
        }
        return penalty <= leftPenalty.back() ? ans : customers.size();
    }
};
