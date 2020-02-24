670. 最大交换
难度
中等

58





给定一个非负整数，你至多可以交换一次数字中的任意两位。返回你能得到的最大值。
示例 1 :
输入: 2736
输出: 7236
解释: 交换数字2和数字7。
示例 2 :
输入: 9973
输出: 9973
解释: 不需要交换。


7---1
6---3
3---2
2---0


/*
思路

转成字符串
再复制成一个char数组，从大到小排序
这样依次比较下来，就能找到第一个不是剩下数字中最大的数，和他的位置
从后往前查找这个数，得到他的位置
交换
转成数字输出

*/

class Solution {
public:
    static bool myfunction (pair<int,int> i,pair<int,int> j) 
    {
         if (i.first > j.first)
         {
             return true;
         }
        else if (i.first == j.first)
        {
            return i.second > j.second;
        }
        else
        {
            return false;
        }
        
        return false;
    }

    int maximumSwap(int num) {
        int old_num = num;
        vector<int> bit_num;
        while(num)
        {
            bit_num.push_back(num % 10);
            num /= 10;
        }
        vector<pair<int, int>> v;
        vector<int> v1;
        int idx = 0;
        for (int i = bit_num.size() - 1; i >= 0; i--)
        {
            v.push_back(pair<int, int>(bit_num[i], idx));
            v1.push_back(bit_num[i]);
            idx += 1;
        }
        sort(v.begin(), v.end(), myfunction);
        int swap_idx = -1;
        for (int i = 0; i < v.size(); i++)
        {
            cout<<v[i].first<<"----"<<v[i].second<<endl;
        }
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i].second != i)
            {
                swap_idx = i;
                break;
            }
        }
        if (swap_idx == -1)
        {
            return old_num;
        }
        else
        {
            swap(v1[swap_idx], v1[v[swap_idx].second]);
        }
        int ans = 0;
        for (int i = 0; i < v1.size(); i++)
        {
            ans *= 10;
            ans += v1[i];
        }

        return ans;
    }
};