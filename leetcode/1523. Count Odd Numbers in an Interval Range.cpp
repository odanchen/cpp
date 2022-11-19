    int countOdds(int low, int high) {
        int ans = (high - low + 1) / 2;
        if ((high % 2 == 1) && (low % 2 == 1)) return ans +1;
        return ans;
    }
