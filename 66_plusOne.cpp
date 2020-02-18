
给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。

最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。

你可以假设除了整数 0 之外，这个整数不会以零开头。

示例 1:

输入: [1,2,3]
输出: [1,2,4]
解释: 输入数组表示数字 123。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/plus-one
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        vector<int> ans;
        int carry = 0;
        digits[digits.size()-1] += 1;
        for (int i = digits.size()-1; i>=0; i--)
        {
            int tmp = digits[i] + carry;
            if (tmp > 9)
            {
                carry = 1;
                ans.push_back(tmp-10);

            }
            else
            {
                carry = 0;
                ans.push_back(tmp);
            }
        }
        if (carry != 0)
        {
            ans.push_back(carry);
        }

        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};