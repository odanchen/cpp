    int firstBadVersion(int n) {
        int left = 1, right = n;
        while(left < right)
        {
            int mid = left / 2  + right / 2;
            if (isBadVersion(mid)) right = mid;
            else left = mid + 1;
        }

        return left;
    }
