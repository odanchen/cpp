    bool isUgly(int n) {
        int div = 2;
        if (n <= 0) return false;
        while(n > 1  && div <= 5)
        {
            if (n % div == 0) n /= div;
            else div++;
        }
        return div <= 5;
    }
