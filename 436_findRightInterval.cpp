/*
	Author:YangGu
	  Date:2020/2/7
*/

/*
给定一组区间，对于每一个区间 i，检查是否存在一个区间 j，它的起始点大于或等于区间 i 的终点，这可以称为 j 在 i 的“右侧”。

对于任何区间，你需要存储的满足条件的区间 j 的最小索引，这意味着区间 j 有最小的起始点可以使其成为“右侧”区间。
如果区间 j 不存在，则将区间 i 存储为 -1。最后，你需要输出一个值为存储的区间值的数组。

注意:


	你可以假设区间的终点总是大于它的起始点。
	你可以假定这些区间都不具有相同的起始点。


示例 1:

输入: [ [1,2] ]
输出: [-1]

解释:集合中只有一个区间，所以输出-1。


示例 2:

输入: [ [3,4], [2,3], [1,2] ]
输出: [-1, 0, 1]

解释:对于[3,4]，没有满足条件的“右侧”区间。
对于[2,3]，区间[3,4]具有最小的“右”起点;
对于[1,2]，区间[2,3]具有最小的“右”起点。

*/

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        /* 起点排序二分法查找 */
        int interval_nums = intervals.size();
        vector<int> interval_start_vec(interval_nums);
        unordered_map<int, int> start_intervalCnt_map;

        for (int i = 0; i < interval_nums; i++)
        {
            interval_start_vec[i] = intervals[i][0];
            start_intervalCnt_map[intervals[i][0]] = i;
        }
        sort(interval_start_vec.begin(), interval_start_vec.end());

        vector<int> ans(interval_nums, -1);
        for (int i = 0; i < interval_nums; i++)
        {
            vector<int>::iterator it = lower_bound(interval_start_vec.begin(), 
												   interval_start_vec.end(),intervals[i][1]);
            if (it != interval_start_vec.end())
            {
                ans[i] = start_intervalCnt_map[*it];
            }
        }
        return ans;

    }
};