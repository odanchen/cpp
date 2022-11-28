    bool isSorted(string &s1, string &s2, vector<int> &hash)
    {
        for (int i = 0; i < s1.size(); i++)
        {
            if (i >= s2.size()) return false;
            if (hash[s1[i] - 'a'] < hash[s2[i] - 'a']) return true;
            if (hash[s1[i] - 'a'] > hash[s2[i] - 'a']) return false;
        }
        return true;
    }
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> hash(order.size());
        for (int i = 0; i < order.size(); i++) hash[order[i] - 'a'] = i;

        for(int i = 0; i < words.size() - 1; i++)
        {
            if (isSorted(words[i], words[i + 1], hash) == false) return false;
        }
        return true;
    }
