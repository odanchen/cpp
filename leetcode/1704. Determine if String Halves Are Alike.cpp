    bool halvesAreAlike(string s) {
        vector<int> temp = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        set<char> vowels(temp.begin(), temp.end());
        int left = 0, right = s.size() - 1;
        int leftVow = 0, rightVow = 0;
        while (left < right)
        {
            if (vowels.find(s[left]) != vowels.end()) leftVow++;
            if (vowels.find(s[right]) != vowels.end()) rightVow++;
            left++; right--;
        }
        return leftVow == rightVow;
    }
