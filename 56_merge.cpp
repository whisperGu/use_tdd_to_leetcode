
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

class Solution
{
public:
    bool my_cmp(<vector<int> &v1, <vector<int> &v2)
    {
        return v1[0] <= v2[0];
    }
    bool could_be_merged(<vector<int> &v1, <vector<int> &v2)
    {
        if (v1[1] < v2[0])
        {
            return false;
        }
        return true;
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals)
     {
        sort(intervals.begin(), intervals.end(), my_cmp);
        
        vector<int> merge = intervals.begin();
        vector<vector<int>> ans;
        for (auto it = intervals.begin(); it < intervals.end(); it = it->next())
        {
            //能合并
            if (could_be_merged(merge, *it))
            {
                merge[1] = max(merge[1], (*it)[1]);
            }
            else
            {
                ans.push_back(merge);
                merge = *it;
            }
        }
        ans.push_back(merge);
        return ans;
    }

};