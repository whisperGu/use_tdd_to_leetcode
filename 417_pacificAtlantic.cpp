/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

    }
};

417. 太平洋大西洋水流问题
给定一个 m x n 的非负整数矩阵来表示一片大陆上各个单元格的高度。“太平洋”处于大陆的左边界和上边界，而“大西洋”处于大陆的右边界和下边界。

规定水流只能按照上、下、左、右四个方向流动，且只能从高到低或者在同等高度上流动。

请找出那些水流既可以流动到“太平洋”，又能流动到“大西洋”的陆地单元的坐标。

 

提示：

输出坐标的顺序不重要
m 和 n 都小于150
 

示例：

 

给定下面的 5x5 矩阵:

  太平洋 ~   ~   ~   ~   ~ 
       ~  1   2   2   3  (5) *
       ~  3   2   3  (4) (4) *
       ~  2   4  (5)  3   1  *
       ~ (6) (7)  1   4   5  *
       ~ (5)  1   1   2   4  *
          *   *   *   *   * 大西洋

返回:

[[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]] (上图中带括号的单元).


// class Solution {
// public:
//     vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {

//     }

//     void dfs(vector<vector<int>>& visted, int i, int j, vector<vector<int>>& matrix)
//     {
//         if (i < 0 || j < 0 || visted[i][j] != -2)
//         {
//             return;
//         }
//         //process

//     }
// };

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<vector<int>> ans;
        int m = matrix.size();
        if (m == 0) return ans;
        int n = matrix[0].size();
        vector<vector<int>> pacific(m, vector<int>(n, 0));
        vector<vector<int>> atlantic(m, vector<int>(n, 0));
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        
        // find pacific
        queue<pair<int, int>> Q;
        for(int i = 0; i < m; i++) {
            pacific[i][0] = 1;
            Q.push(make_pair(i, 0));
        }
        for(int j = 1; j < n; j++) {
            pacific[0][j] = 1;
            Q.push(make_pair(0, j));
        }
        while(!Q.empty()) {
            pair<int, int> pos = Q.front();
            Q.pop();

            for (int d = 0; d < 4; d++) {
                int ii = pos.first + dx[d];
                int jj = pos.second + dy[d];
                if (ii < 0 || jj < 0 || ii >= m || jj >= n) continue;
                if (pacific[ii][jj]) continue;
                if (matrix[ii][jj] >= matrix[pos.first][pos.second]) {
                    pacific[ii][jj] = 1;
                    Q.push(make_pair(ii, jj));
                }
            }
        }

        for(int i = 0; i < m; i++) {
            atlantic[i][n-1] = 1;
            Q.push(make_pair(i, n-1));
        }
        for(int j = 0; j < n-1; j++) {
            atlantic[m-1][j] = 1;
            Q.push(make_pair(m-1, j));
        }
        while(!Q.empty()) {
            pair<int, int> pos = Q.front();
            Q.pop();

            for (int d = 0; d < 4; d++) {
                int ii = pos.first + dx[d];
                int jj = pos.second + dy[d];
                if (ii < 0 || jj < 0 || ii >= m || jj >= n) continue;
                if (atlantic[ii][jj]) continue;
                if (matrix[ii][jj] >= matrix[pos.first][pos.second]) {
                    atlantic[ii][jj] = 1;
                    Q.push(make_pair(ii, jj));
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (atlantic[i][j] && pacific[i][j]) ans.push_back(vector<int>{i, j});
            }
        }

        return ans;
    }
};





