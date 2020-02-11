/*
给定一个字符串S，通过将字符串S中的每个字母转变大小写，我们可以获得一个新的字符串。返回所有可能得到的字符串集合。

示例:
输入: S = "a1b2"
输出: ["a1b2", "a1B2", "A1b2", "A1B2"]

输入: S = "3z4"
输出: ["3z4", "3Z4"]

输入: S = "12345"
输出: ["12345"]

来源：力扣（LeetCode）

*/

class Solution 
{
public:
    void func(int i, string S, vector<string> &res)
    {
        if(i!=S.size())
        {
            if(S[i]>='A' && S[i]<='Z') 
            {
                
                func(i+1,S,res);
                S[i]+=32;
                func(i+1,S,res);
            }
            else if(S[i]>='a' && S[i]<='z') 
            {
                
                func(i+1,S,res);
                S[i]-=32;
                func(i+1,S,res);
            }
            else
            {
                func(i+1,S,res);
            }
        }

        else
        {
            res.push_back(S);
        }

    }


    vector<string> letterCasePermutation(string S)
    {
        vector<string> res;
        func(0,S,res);
        return res; 
    }
};
