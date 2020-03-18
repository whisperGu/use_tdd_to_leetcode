
56. 合并区间
给出一个区间的集合，请合并所有重叠的区间。

示例 1:

输入: [[1,3],[2,6],[8,10],[15,18]]
输出: [[1,6],[8,10],[15,18]]
解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
示例 2:

输入: [[1,4],[4,5]]
输出: [[1,5]]
解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        if (intervals.empty()) return res;
        sort(intervals.begin(), intervals.end(),
            [&, this](vector<int> &v1, vector<int> &v2) { return v1[0] < v2[0];});
        
        for (int i = 0; i < intervals.size(); ++i) {
            vector<int> temp = intervals[i];
            while (i + 1 < intervals.size() && temp[1] >= intervals[i+1][0]) {
                ++i;
                temp[1] = max(temp[1], intervals[i][1]);
            }
            res.push_back(temp);
        }
        return res;
    }
};
