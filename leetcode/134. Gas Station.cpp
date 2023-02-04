class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {  
        int start = 0, sum = 0, check = 0;
        for (int i = 0; i < gas.size(); i++) {
            check += gas[i] - cost[i];
            sum += gas[i] - cost[i];
            if (sum < 0) {
                start = i + 1;
                sum = 0;
            }
        }
        return check < 0 ? -1 : start;
    }
};
