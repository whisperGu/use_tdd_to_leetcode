/*
 * Author: YangGu 
 *   Date: 2020/2/3
*/

#define CATCH_CONFIG_MAIN  

#include <catch.hpp>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;
/*
 * 数字转换为十六进制数
 * 十六进制中所有字母(a-f)都必须是小写。
 * 十六进制字符串中不能包含多余的前导零。
 * 如果要转化的数为0，那么以单个字符'0'来表示；
 * 对于其他情况，十六进制字符串中的第一个字符将不会是0字符。
 * 给定的数确保在32位有符号整数范围内。
 * 不能使用任何由库提供的将数字直接转换或格式化为十六进制的方法。
*/
const int HEX_MOD = 16;
const int DEC_MOD = 10;
string nonNegativetoHex(long long num);

string toHex(int num)
{
    long long dw_num = num;
    if (num < 0)
    {
        dw_num = 0x100000000 + num;
    }

    return nonNegativetoHex(dw_num);
}

string nonNegativetoHex(long long num)
{
    if (num == 0)
    {
        return "0";
    }
    string hex_str = "";
    while (num != 0)
    {
        int mod = num % HEX_MOD;
        if (mod >= DEC_MOD)
        {
            hex_str += ('a' + mod - DEC_MOD);
        }
        else
        {
            hex_str += ('0' + mod);
        }
        num = num / HEX_MOD;
    }

    reverse(hex_str.begin(), hex_str.end());

    return hex_str;
}

SCENARIO("decimal to hex") 
{
    GIVEN("toHex") 
    {
        int input_decimal_num = 0;

        WHEN("input 26") 
        {
            input_decimal_num = 26;
            THEN("get 1a") 
            {
                REQUIRE(toHex(input_decimal_num) == "1a");
            }
        }

        WHEN("input -1")
        {
            input_decimal_num = -1;
            THEN("get ffffffff")
            {
                REQUIRE(toHex(input_decimal_num) == "ffffffff");
            }
        }

        WHEN("input 0")
        {
            input_decimal_num = 0;
            THEN("get 0")
            {
                REQUIRE(toHex(input_decimal_num) == "0");
            }
        }

        WHEN("input 1")
        {
            input_decimal_num = 1;
            THEN("get 1")
            {
                REQUIRE(toHex(input_decimal_num) == "1");
            }
        }

        WHEN("input -270")
        {
            input_decimal_num = -270;
            THEN("get fffffef2")
            {
                REQUIRE(toHex(input_decimal_num) == "fffffef2");
            }
        }
    }
}

