/*
给你一个由若干 0 和 1 组成的二维网格 grid，请你找出边界全部由 1 组成的最大 正方形 子网格，并返回该子网格中的元素数量。如果不存在，则返回 0。

 

示例 1：

输入：grid = [[1,1,1],[1,0,1],[1,1,1]]
输出：9

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/largest-1-bordered-square
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    bool valid(const vector<vector<int> >& grid, int r, int c, int s) {
        for (int i = 0; i < s; ++i) {
            if (grid[r + i][c] + grid[r + i][c + s - 1] + 
                    grid[r][c + i] + grid[r + s - 1][c + i] != 4) 
                return false;
        }
        return true;
    }
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        int R = grid.size();
        int C = grid[0].size();
        for (int s = min(R, C); s >= 1; --s) {
            for (int i = 0; i < R && i + s - 1 < R; ++i) {
                for (int j = 0; j < C && j + s - 1 < C; ++j) {
                    if (valid(grid, i, j, s)) return s * s;
                }
            }
        }
        return 0;
    }
};