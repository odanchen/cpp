class Solution {
public:
    int minTimeToType(string word) {
        char letter = 'a';
        int time = 0;
        for (char c: word) {
            time += min(abs(letter - c), min(abs(letter + 26 - c), abs(letter - 26 - c)));
            letter = c;
        }
        return time + word.size();
    }
};
