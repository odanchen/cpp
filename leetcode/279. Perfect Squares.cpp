class Solution {
public:
    int numSquares(int n) {
        vector<int> partNums(n + 1), squares;
        queue<int> toProcess;
        for (int i = 1; i * i <= n; i++) {
            partNums[i * i] = 1;
            toProcess.push(i * i);
            squares.push_back(i * i);
        }
        while(!toProcess.empty()) {
            int cur = toProcess.front();
            toProcess.pop();
            for (int val : squares) {
                if (cur + val <= n and partNums[cur + val] == 0) {
                    partNums[cur + val] = partNums[cur] + 1;
                    toProcess.push(cur + val);
                }
            }
        }
        return partNums.back();
    }
};
