/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int left = 1, right = n;
        long long mid = (left / 2.0 + right / 2.0);
        while(guess(mid) != 0)
        {
            if (guess(mid) == 1) left = mid + 1;
            else right = mid - 1;
            mid = (left / 2.0 + right / 2.0);
        }

        return mid;
    }
};
