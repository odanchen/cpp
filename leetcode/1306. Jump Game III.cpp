    bool inside(int idx, vector<int> &arr)
    {
        return (idx >= 0 && idx < arr.size());
    }
    bool canBeReached(int start, vector<int> &arr, vector<bool> &visited)
    {
        if (arr[start] == 0) return true;

        visited[start] = true;
        int idx1 = start + arr[start];
        int idx2 = start - arr[start];
        bool exp1 = inside(idx1, arr) && not(visited[idx1]) && canBeReached(idx1, arr, visited);
        bool exp2 = inside(idx2, arr) && not(visited[idx2]) && canBeReached(idx2, arr, visited);

        return exp1 || exp2;
    }
    bool canReach(vector<int>& arr, int start) {
        vector<bool> visited(arr.size());
        return canBeReached(start, arr, visited);
    }
