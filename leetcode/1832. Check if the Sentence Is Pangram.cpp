class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> checklist(26);
        int toMeet = 26;
        for (char c: sentence) if (checklist[c - 'a']++ == 0) toMeet--;
        return toMeet == 0;
    }
};
