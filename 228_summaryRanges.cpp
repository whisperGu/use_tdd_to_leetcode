228. 汇总区间

给定一个无重复元素的有序整数数组，返回数组区间范围的汇总。
示例 1:
输入: [0,1,2,4,5,7]
输出: ["0->2","4->5","7"]
解释: 0,1,2 可组成一个连续的区间; 4,5 可组成一个连续的区间。

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.size() == 0)
        {
            vector<string> ans;
            return ans;
        }
		int left = nums[0];
		int right = nums[0];
		vector<string> ans;
		for (int i = 1; i < nums.size(); i++)
		{
			if (right + 1 == nums[i])
			{
				right++;
			}
			else
			{
                string c;
				if (left == right)
				{
					ans.push_back(std::to_string(left));
				}
				else
				{
					ans.push_back(std::to_string(left)+"->"+std::to_string(right));
				}
                left = nums[i];
                right = nums[i];
			}
		}
        if(left == right)
        {
            ans.push_back(std::to_string(left));
        }
		else
        {
            ans.push_back(std::to_string(left)+"->"+std::to_string(right));
        }
		return ans;
		
    }
};