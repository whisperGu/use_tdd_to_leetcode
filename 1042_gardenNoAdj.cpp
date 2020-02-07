/*
	Author:YangGu
	  Date:2020/2/7
*/

/*
有 N 个花园，按从 1 到 N 标记。在每个花园中，你打算种下四种花之一。

paths[i] = [x, y] 描述了花园 x 到花园 y 的双向路径。

另外，没有花园有 3 条以上的路径可以进入或者离开。

你需要为每个花园选择一种花，使得通过路径相连的任何两个花园中的花的种类互不相同。

以数组形式返回选择的方案作为答案 answer，其中 answer[i] 为在第 (i+1) 个花园中种植的花的种类。花的种类用  1, 2, 3, 4 表示。保证存在答案。

示例 1：

输入：N = 3, paths = [[1,2],[2,3],[3,1]]
输出：[1,2,3]

*/

class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        unordered_map<int, vector<int>> map;
        for (int i = 0; i < paths.size(); i++)
        {
             map[paths[i][0]].push_back(paths[i][1]);
             map[paths[i][1]].push_back(paths[i][0]);
        }
        vector<int> ans(N,0);
        for (int i = 1; i <= N; i++)
        {
            for (int color_cnt = 1; color_cnt <= 4; color_cnt++)
            {
                bool this_color_could_use = true;
                vector<int> its_neighbours_garden = map[i];
                for (int j = 0; j < its_neighbours_garden.size(); j++)
                {
                    if (ans[its_neighbours_garden[j]-1] == color_cnt)
                    {
                        this_color_could_use = false;
                        break;
                    }
                }
                if (this_color_could_use)
                {
                    ans[i-1] = color_cnt;
                    break;
                }
            }
        }
        return ans;
    }
};