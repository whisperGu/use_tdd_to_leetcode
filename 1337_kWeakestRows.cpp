
--------28号-------------

1337. 方阵中战斗力最弱的 K 行
给你一个大小为 m * n 的方阵 mat，方阵由若干军人和平民组成，分别用 0 和 1 表示。

请你返回方阵中战斗力最弱的 k 行的索引，按从最弱到最强排序。

如果第 i 行的军人数量少于第 j 行，或者两行军人数量相同但 i 小于 j，那么我们认为第 i 行的战斗力比第 j 行弱。

军人 总是 排在一行中的靠前位置，也就是说 1 总是出现在 0 之前。

 

示例 1：

输入：mat = 
[[1,1,0,0,0],
 [1,1,1,1,0],
 [1,0,0,0,0],
 [1,1,0,0,0],
 [1,1,1,1,1]], 
k = 3
输出：[2,0,3]
解释：
每行中的军人数目：
行 0 -> 2 
行 1 -> 4 
行 2 -> 1 
行 3 -> 2 
行 4 -> 5 
从最弱到最强对这些行排序后得到 [2,0,3,1,4]


class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int rows = mat.size();
        int cols = mat[0].size();
        vector<pair<int,int>> armycnt_rowcnt_v;

        int army_cnt = 0;
        for (int i = 0; i < rows; i++)
        {
            army_cnt = 0;
            for (int j = 0; j < cols; j++)
            {
                if (mat[i][j] == 1)
                {
                    army_cnt++;
                }
            }
            armycnt_rowcnt_v.push_back({army_cnt,i});
        }

        sort(armycnt_rowcnt_v.begin(),armycnt_rowcnt_v.end());
        vector<int> x;
        for (int i = 0; i < k; i++)
        {
            x.push_back(armycnt_rowcnt_v[i].second);
        }
        
        return x;
    }
};