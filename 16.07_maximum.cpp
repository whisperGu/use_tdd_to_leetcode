面试题 16.07. 最大数值

编写一个方法，找出两个数字a和b中最大的那一个。不得使用if-else或其他比较运算符。
示例：
输入： a = 1, b = 2
输出： 2


class Solution {
public:
    int maximum(int a, int b) {

    }
};


var >= 0: var >> 7 => 0x00，即：(var ^ 0x00) - 0x00，异或结果为var


var < 0: var >> 7 => 0xFF，即：(var ^ 0xFF) - 0xFF，var ^ 0xFF是在对var的全部位取反，-0xFF <=> +1,
 对signed int取反加一就是取其相反数。

基于上述分析：



类型
绝对值位运算




int8_t
(var ^ (var >> 7)) - (var >> 7)


int16_t
(var ^ (var >> 15)) - (var >> 15)


int32_t
(var ^ (var >> 31)) - (var >> 31)


int64_t
(var ^ (var >> 63)) - (var >> 63)

