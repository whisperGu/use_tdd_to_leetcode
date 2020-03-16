

908. 最小差值 I
给定一个整数数组 A，对于每个整数 A[i]，我们可以选择任意 x 满足 -K <= x <= K，并将 x 加到 A[i] 中。

在此过程之后，我们得到一些数组 B。

返回 B 的最大值和 B 的最小值之间可能存在的最小差值。

 

示例 1：

输入：A = [1], K = 0
输出：0
解释：B = [1]
示例 2：

输入：A = [0,10], K = 2
输出：6
解释：B = [2,8]
示例 3：

输入：A = [1,3,6], K = 3
输出：0
解释：B = [3,3,3] 或 B = [4,4,4]

class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        int len = A.size();
        if (len <= 1)
        {
            return 0;
        }
        int A_min = A[0];
        int A_max = A[0];
        for (int i = 1; i < len; i++)
        {
            if (A[i] > A_max)
            {
                A_max = A[i];
            }
            if (A[i] < A_min)
            {
                A_min = A[i];
            }
        }
        int diff = A_max - A_min;
        if (diff <= 2*K)
        {
            return 0;
        }
        return diff - 2 * K ;
    }
};
