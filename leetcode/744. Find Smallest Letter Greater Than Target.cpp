class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        if (letters.back() <= target) return letters.front();
        int left = 0, right = letters.size() - 1, mid;
        while(left < right) {
            mid = (left + right) / 2;
            if (letters[mid] <= target) left = mid + 1;
            else right = mid;
        }
        return letters[left];
    }
};
