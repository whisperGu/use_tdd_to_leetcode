888. 公平的糖果交换
难度
简单

57





爱丽丝和鲍勃有不同大小的糖果棒：A[i] 是爱丽丝拥有的第 i 块糖的大小，B[j] 是鲍勃拥有的第 j 块糖的大小。
因为他们是朋友，所以他们想交换一个糖果棒，这样交换后，他们都有相同的糖果总量。（一个人拥有的糖果总量是他们拥有的糖果棒大小的总和。）
返回一个整数数组 ans，其中 ans[0] 是爱丽丝必须交换的糖果棒的大小，ans[1] 是 Bob 必须交换的糖果棒的大小。
如果有多个答案，你可以返回其中任何一个。保证答案存在。
 
示例 1：
输入：A = [1,1], B = [2,2]
输出：[1,2]


class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int sum = 0;
        int A_candys = 0;
        for (int i = 0 ; i < A.size(); i++)
        {
            sum += A[i];
            A_candys += A[i];
        }
        unordered_map<int, int> map;
        for (int i = 0 ; i < B.size(); i++)
        {
            sum += B[i];
            map[B[i]] += 1;
        }
        int diff_candy = sum / 2 - A_candys;
        vector<int> ans;
        for (int i = 0 ; i < A.size(); i++)
        {
            int swap_candy =  A[i] + diff_candy;
            if (map[swap_candy] > 0)
            {
                ans.push_back(A[i]);
                ans.push_back(swap_candy);
                break;
            }
        }
        return ans;
    }
};