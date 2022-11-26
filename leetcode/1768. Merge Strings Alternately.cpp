    string mergeAlternately(string word1, string word2) {
        string ans;
        ans.resize(word1.size() + word2.size());
        string::iterator it1 = word1.begin();
        string::iterator it2 = word2.begin();
        string::iterator ansit = ans.begin();
        while(ansit != ans.end())
        {
            if(it1 == word1.end())
            {
                *ansit = *it2; it2++;
            }
            else if(it2 == word2.end())
            {
                *ansit = *it1; it1++;
            }
            else
            {
                *ansit = *it1; it1++; ansit++;
                *ansit = *it2; it2++;
            }
            ansit++;
        }
        return ans;
    }
