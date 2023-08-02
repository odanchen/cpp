class Solution {
public:
    string predictPartyVictory(string senate) {
        int rad = 0, dire = 0, cur = 0, idx = 0;
        for (char c : senate) (c == 'R' ? rad : dire)++;
        while (rad > 0 and dire > 0) {
            if (senate[idx] == 'R') {
                if (cur < 0) {
                    rad--;
                    senate[idx] = '0';
                }
                cur++;
            } else if (senate[idx] == 'D') {
                    if (cur > 0) {
                    dire--;
                    senate[idx] = '0';
                }
                cur--;
            }
            idx = (idx + 1) % senate.size();
        }
        return rad > 0 ? "Radiant" : "Dire";
    }
};
