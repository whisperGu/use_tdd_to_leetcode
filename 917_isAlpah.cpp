917. 仅仅反转字母
难度
简单

41





给定一个字符串 S，返回 “反转后的” 字符串，其中不是字母的字符都保留在原地，而所有字母的位置发生反转。
 

示例 1：
输入："ab-cd"
输出："dc-ba"
示例 2：
输入："a-bC-dEf-ghIj"
输出："j-Ih-gfE-dCba"

class Solution {
public:

    bool isAlpah(char c)
    {
        if ((c>= 'a' && c <= 'z') || (c>= 'A' && c <= 'Z'))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    string reverseOnlyLetters(string S) {

        int i = 0;
        int j = S.size()-1;
        while (i < j)
        {
            while (isAlpah(S[i]) == false)
            {
                i++;
            }
            while (isAlpah(S[j]) == false)
            {
                j--;
            }
            if (i < j)
            {
                char tmp = S[i];
                S[i] = S[j];
                S[j] = tmp;
                i++;
                j--;
            }
            else
            {
                break;
            }

        }
        return S;

    }
};