    char findTheDifference(string s, string t) {
        int missing = 0;
        for (char letter : s) missing = missing ^ ((int) letter);
        for (char letter : t) missing = missing ^ ((int) letter);
        return (char)missing;
    }
