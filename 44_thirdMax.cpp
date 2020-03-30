
414. 第三大的数
难度
简单

109





给定一个非空数组，返回此数组中第三大的数。如果不存在，则返回数组中最大的数。要求算法时间复杂度必须是O(n)。
示例 1:
输入: [3, 2, 1]

输出: 1

解释: 第三大的数是 1.

class Solution {
public:
int thirdMax(int* nums, int numsSize)
{
	long first = LONG_MIN, second = LONG_MIN, third = LONG_MIN;
	if (numsSize == 1)
		return *nums;
	else if (numsSize == 2)
		return *nums > *(nums + 1) ? *nums : *(nums + 1);
	for (int i = 0; i < numsSize; ++i)
	{
		if (first < nums[i])
		{
			third = second;
			second = first;
			first = nums[i];
		}
		else if (first > nums[i] && second < nums[i])
		{
			third = second;
			second = nums[i];
		}
		else if (second > nums[i] && third < nums[i])
		{
			third = nums[i];
		}

	}
	if (third == LONG_MIN)
		return first;
	return third;
}
};