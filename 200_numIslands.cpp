/*
 * Author: YangGu 
 *   Date: 2020/2/6
*/

#define CATCH_CONFIG_MAIN  

#include <catch.hpp>
#include <vector>

using namespace std;

 /**
    给定一个由 '1'（陆地）和 '0'（水）组成的的二维网格，计算岛屿的数量。一个岛被水包围，
    并且它是通过水平方向或垂直方向上相邻的陆地连接而成的。你可以假设网格的四个边均被水包围。

    示例 1:

    输入:
    11110
    11010
    11000
    00000

    输出: 1
  */
void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j)
void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j)
{
	int nr = grid.size();
    int nc = grid[0].size();
	
    if (i >= nr || j >= nc|| i < 0 || j < 0)
    {
        return;
    }
    if (grid[i][j] == '0' || visited[i][j] == true)
    {
        return;
    }

    visited[i][j] = true;

    dfs(grid, visited, i+1, j);
    dfs(grid, visited, i, j+1);
    dfs(grid, visited, i-1, j);
    dfs(grid, visited, i, j-1);
}

int numIslands(vector<vector<char>>& grid) 
{
    /* dfs 找矩阵连通区域个数 */
    int n_rows = grid.size();
    if (n_rows == 0)
    {
        return 0;
    }
    int n_cols = grid[0].size();


    vector<vector<bool>> visited(n_rows, vector<bool>(n_cols, false));
    int res = 0;
    for (int i = 0; i < n_rows; i++)
    {
        for (int j = 0; j < n_cols; j++)
        {
            if (grid[i][j] == '1' && visited[i][j] == false)
            {
                res++;
                dfs(grid, visited, i , j);              
            }
        }
    }
    return res;
}

SCENARIO("numIslands ") 
{
    GIVEN("numIslands") 
    {
        WHEN("grid is \n11110\n11010\n11000\n00000") 
        {
            vector<vector<char>> grid = { {1,1,1,1,0} ,{1,1,0,1,0} ,{1,1,0,0,0} ,{0,0,0,0,0} };
            THEN("Island number is 1 ") 
            {
                REQUIRE(numIslands(grid) == 1);
            }
        }
    }
}



