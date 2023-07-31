class Solution {
public:
    vector<int> asteroidCollision(vector<int> &asteroids) {
        vector<int> ans;
        for (int val: asteroids) {
            if (ans.empty() or val > 0 or (val < 0 and ans.back() < 0)) ans.push_back(val);
            else {
                while (!ans.empty() and ans.back() > 0 and ans.back() < abs(val)) ans.pop_back();
                if (!ans.empty() and ans.back() > 0 and ans.back() == abs(val)) ans.pop_back();
                else if (ans.empty() or ans.back() < 0) ans.push_back(val);
            }
        }
        return ans;
    }
};
