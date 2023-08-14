class Solution {
public:
    int countDigits(int num) {
        int copy = num, cnt = 0;
        while (copy) {
            if (num % (copy % 10) == 0) cnt++;
            copy /= 10;
        }   
        return cnt;
    }
};
