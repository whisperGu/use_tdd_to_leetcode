/*
给定一个整数数组 A，只有我们可以将其划分为三个和相等的非空部分时才返回 true，否则返回 false。

形式上，如果我们可以找出索引 i+1 < j 且满足 (A[0] + A[1] + ... + A[i] == A[i+1] + A[i+2] + ... + A[j-1] == A[j] + A[j-1] + ... + A[A.length - 1]) 就可以将数组三等分。

 

示例 1：

输出：[0,2,1,-6,6,-7,9,1,2,0,1]
输出：true
解释：0 + 2 + 1 = -6 + 6 - 7 + 9 + 1 = 2 + 0 + 1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/partition-array-into-three-parts-with-equal-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int sum = 0;
        for (int i = 0; i < A.size();i++)
        {
            sum += A[i];
        }
        if (sum % 3 != 0)
        {
            return false;
        }
        int cnt = 0;
        int s = 0;
        for (int i = 0; i < A.size();i++)
        {
            s += A[i];
            if (s == sum/3)
            {
                cnt += 1;
                s = 0;
            }
        }

        if (cnt == 3)
        {
            return true;
        }
        return false;
    }
};