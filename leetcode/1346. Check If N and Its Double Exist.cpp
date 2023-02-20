class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        set<int> toFind;
        for (int val : arr) {
            if (toFind.find(val) == toFind.end()) {
                toFind.insert(val * 2); 
                if (val % 2 == 0) toFind.insert(val / 2);
            }
            else return true;
        }
        return false;
    }
};
