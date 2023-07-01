class Solution {
public:
    struct Distribution {
        vector<int> cookies;
        vector<int> kids;
        uint8_t cookiesTaken = 1;
        uint8_t distributed = 1;
        uint8_t notReceived;
        
        Distribution(vector<int> &cookies, int k) : cookies(cookies), kids(vector<int>(k)) {
            kids[0] = cookies[0];
            notReceived = kids.size() - 1;
        }
        
        bool isTaken(int idx) {
            return cookiesTaken & (1 << idx);
        }
        
        void takeCookie(int idx, int childIdx) {
            distributed++;
            if (kids[childIdx] == 0) notReceived--;
            cookiesTaken |= (1 << idx);
            kids[childIdx] += cookies[idx];
        }
        
        void unTakeCookie(int idx, int childIdx) {
            distributed--;
            cookiesTaken &= ~(1 << idx);
            kids[childIdx] -= cookies[idx];
            if (kids[childIdx] == 0) notReceived++;
        }
        
        bool isComplete() {
            return distributed == cookies.size();
        }
        
        int getUnfairness() {
            return *max_element(kids.begin(), kids.end());
        }
        
        int cookiesLeft() {
            return (int) (cookies.size() - distributed);
        }
    };

    void backtrack(Distribution &dist, int &ans) {
        if (dist.isComplete()) {
            ans = ans == 0 ? dist.getUnfairness() : min(ans, dist.getUnfairness());
            return;
        }

        int i = dist.distributed;
        for (int j = 0; j < dist.kids.size(); j++) {
            if (dist.cookiesLeft() == dist.notReceived && dist.kids[j] != 0) continue;
            dist.takeCookie(i, j);
            backtrack(dist, ans);
            dist.unTakeCookie(i, j);
        }
    }

    int distributeCookies(vector<int>& cookies, int k) {
        Distribution dist(cookies, k);
        int ans = 0;
        backtrack(dist, ans);
        return ans;
    }
};
