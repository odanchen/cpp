    int findCandidate(set<int> &nonTrusters, vector<int> &trusted, int n)
    {
        vector<int> potentialJudges;
        for (int i = 1; i < trusted.size(); i++)
        {
            if (trusted[i] == n - 1) potentialJudges.push_back(i);
        }

        for (int candidate : potentialJudges)
        {
            if (nonTrusters.find(candidate) != nonTrusters.end()) return candidate;
        }

        return -1;
    }
    int findJudge(int n, vector<vector<int>>& trust) {
        set<int> nonTrusters;
        vector<int> trusted(n + 1);
        for (int i = 1; i <= n; i++) nonTrusters.insert(i);

        for (vector<int> connection : trust)
        {
            trusted[connection[1]]++;
            if (nonTrusters.find(connection[0]) != nonTrusters.end()) nonTrusters.erase(connection[0]);
        }

        return findCandidate(nonTrusters, trusted, n);
    }
