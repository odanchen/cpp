    bool areAlmostEqual(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        vector<int> mismatches;

        for (int i = 0; i < s1.size(); i++) if (s1[i] != s2[i]) mismatches.push_back(i);
        
        if (mismatches.size() != 2) return mismatches.empty();
        return (s1[mismatches[0]] == s2[mismatches[1]] && s1[mismatches[1]] == s2[mismatches[0]]);
    }
