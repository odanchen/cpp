    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int dif = arr[0] - arr[1];
        for (int i = 1; i < arr.size() - 1; i++) 
        {
            int curdif = arr[i] - arr[i + 1];
            if (curdif != dif) return false;
        }

        return true;
    }
