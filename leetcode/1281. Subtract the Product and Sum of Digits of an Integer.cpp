    int subtractProductAndSum(int n) {
       int sum = 0, mlt = 1;
       while(n > 0)
       {
           sum += n % 10;
           mlt *= n % 10;
           n /= 10;
       } 
       return mlt - sum;
    }
