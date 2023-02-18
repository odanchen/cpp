class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" or num2 == "0") return "0";
        vector<int> ansArr(num1.size() + num2.size());
        if (num1.size() < num2.size()) swap(num1, num2);

        for (int n2 = num2.size() - 1; n2 >= 0; n2--) {
            int temp = 0;
            int idx = ansArr.size() - 1 - (num2.size() - 1 - n2);
            for (int n1 = num1.size() - 1; n1 >= 0; n1--) {
                int mlt = (ansArr[idx] + (num2[n2] - '0') * (num1[n1] - '0') + temp);
                ansArr[idx] = mlt % 10;
                temp = mlt / 10;
                idx--;
            }
            while (temp != 0) {
                int mlt = (ansArr[idx] + temp);
                ansArr[idx] = mlt % 10;
                temp = mlt / 10;
            }
        }

        int left = 0;
        string ans;
        while(ansArr[left] == 0) left++;
        for (; left < ansArr.size(); left++) ans.push_back(ansArr[left] + '0');
        return ans;
    }
};
