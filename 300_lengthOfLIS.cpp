300. 最长上升子序列
难度
中等

568

收藏

分享

切换为英文

关注

反馈
给定一个无序的整数数组，找到其中最长上升子序列的长度。
示例:
输入: [10,9,2,5,3,7,101,18]
输出: 4 
解释: 最长的上升子序列是 [2,3,7,101]，它的长度是 4。
说明:
可能会有多种最长上升子序列的组合，你只需要输出对应的长度即可。
你算法的时间复杂度应该为 O(n2) 。

最后整个算法流程为：


设当前已求出的最长上升子序列的长度为 len\textit{len}len（初始时为 111），
从前往后遍历数组 nums\textit{nums}nums，在遍历到 nums[i]\textit{nums}[i]nums[i] 时：


如果 nums[i]>d[len]\textit{nums}[i] > d[\textit{len}]nums[i]>d[len] ，
则直接加入到 ddd 数组末尾，并更新 len=len+1\textit{len} = \textit{len} + 1len=len+1；


否则，在 ddd 数组中二分查找，找到第一个比 nums[i]\textit{nums}[i]nums[i] 小的数 d[k]d[k]d[k] ，并更新 d[k+1]=nums[i]d[k + 1] = \textit{nums}[i]d[k+1]=nums[i]。




以输入序列 [0,8,4,12,2][0, 8, 4, 12, 2][0,8,4,12,2] 为例：


第一步插入 000，d=[0]d = [0]d=[0]；


第二步插入 888，d=[0,8]d = [0, 8]d=[0,8]；


第三步插入 444，d=[0,4]d = [0, 4]d=[0,4]；


第四步插入 121212，d=[0,4,12]d = [0, 4, 12]d=[0,4,12]；


第五步插入 222，d=[0,2,12]d = [0, 2, 12]d=[0,2,12]。


最终得到最大递增子序列长度为 333。

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = 1, n = (int)nums.size();
        if (n == 0) return 0;
        vector<int> d(n + 1, 0);
        d[len] = nums[0];
        for (int i = 1; i < n; ++i) {
            if (nums[i] > d[len]) d[++len] = nums[i];
            else{
                int l = 1, r = len, pos = 0; // 如果找不到说明所有的数都比 nums[i] 大，此时要更新 d[1]，所以这里将 pos 设为 0
                while (l <= r) {
                    int mid = (l + r) >> 1;
                    if (d[mid] < nums[i]) {
                        pos = mid;
                        l = mid + 1;
                    }
                    else r = mid - 1;
                }
                d[pos + 1] = nums[i];
            }
        }
        return len;
    }
};







