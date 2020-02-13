/*
在MATLAB中，有一个非常有用的函数 reshape，它可以将一个矩阵重塑为另一个大小不同的新矩阵，但保留其原始数据。

给出一个由二维数组表示的矩阵，以及两个正整数r和c，分别表示想要的重构的矩阵的行数和列数。

重构后的矩阵需要将原始矩阵的所有元素以相同的行遍历顺序填充。

如果具有给定参数的reshape操作是可行且合理的，则输出新的重塑矩阵；否则，输出原始矩阵。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reshape-the-matrix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int old_row = nums.size();
        if (old_row == 0)
        {
            return nums;
        }
        int old_col = nums[0].size();
        if (old_row*old_col != r * c)
        {
            return nums;
        }

        vector<vector<int>> ans(r, vector<int>(c));
        int k1 = 0;
        int k2 = 0;
        for (int i = 0; i < old_row; i++)
        {
            for (int j = 0; j < old_col; j++)
            {
                ans[k1][k2] = nums[i][j];
                k2++;
                if (k2 == c)
                {
                    k1++;
                    k2 = 0;
                }
            }
        }
        return ans;
    }
};