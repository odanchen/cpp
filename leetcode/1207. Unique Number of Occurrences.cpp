    bool uniqueOccurrences(vector<int>& arr) {
        map<int, int> occurrances;
        for (int element : arr) 
        {
            if (occurrances.find(element) == occurrances.end()) occurrances.insert(pair<int, int>(element, 1));
            else occurrances[element] += 1; 
        }
        set<int> uniqueOccurrances;
        map<int, int>::iterator it = occurrances.begin();
        while(it != occurrances.end())
        {
            if (uniqueOccurrances.find(it->second) == uniqueOccurrances.end()) 
            {
                uniqueOccurrances.insert(it->second);
                it++;
            }
            else return false;
        }
        return true;
    }
