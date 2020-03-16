面试题 17.09. 第 k 个数
难度
中等

2





有些数的素因子只有 3，5，7，请设计一个算法找出第 k 个数。注意，不是必须有这些素因子，而是必须不包含其他的素因子。例如，前几个数按顺序应该是 1，3，5，7，9，15，21。
示例 1:
输入: k = 5

输出: 9

class Solution {
public:
    int getKthMagicNumber(int k) {
        vector<long long> dp(k+1, 0);
        dp[0] = 1;
        for (int i = 1; i < k; i++) {
            long long mini = LLONG_MAX;
            auto iter = upper_bound(dp.begin(), dp.begin()+i, dp[i-1] / 3);
            mini = min(mini, *iter * 3);
            iter = upper_bound(dp.begin(), dp.begin()+i, dp[i-1] / 5);
            mini = min(mini, *iter * 5);
            iter = upper_bound(dp.begin(), dp.begin()+i, dp[i-1] / 7);
            mini = min(mini, *iter * 7);
            dp[i] = mini;
        } 
        return dp[k-1];
    }
};