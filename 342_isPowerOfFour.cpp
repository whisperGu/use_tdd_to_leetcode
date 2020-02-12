/*
给定一个整数 (32 位有符号整数)，请编写一个函数来判断它是否是 4 的幂次方。
示例 1:
输入: 16
输出: true
*/

class Solution {
public:
    bool isPowerOfFour(int num) {
        while (num)
        {
            if (num == 1)
            {
                return true;
            }
            if (num % 4 != 0)
            {
                return false;
            }
            num /= 4;
        }
        return false;
    }

};

/*
class Solution {
public:
    bool isPowerOfFour(int num) {
        return num > 0 && !(num & (num - 1)) && (num & 0x55555555) == num;
    }
};
*/