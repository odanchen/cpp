class Solution {
public:
    int maximum69Number(int num) {
        int grade = 1;
        while (grade < num) grade *= 10;
        while (grade > 0 and ((num % grade) / (grade == 1 ? 1 : grade / 10) == 9)) grade /= 10;
        return num + (grade / 10) * 3;
    }
};
