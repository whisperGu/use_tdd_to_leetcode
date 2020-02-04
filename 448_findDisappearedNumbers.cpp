/*
 * Author: YangGu 
 *   Date: 2020/2/4
*/

#define CATCH_CONFIG_MAIN  

#include <catch.hpp>
#include <vector>


using namespace std;
/*
给定一个范围在  1 ≤ a[i] ≤ n ( n = 数组大小 ) 的 整型数组，数组中的元素一些出现了两次，另一些只出现一次。

找到所有在 [1, n] 范围之间没有出现在数组中的数字。

您能在不使用额外空间且时间复杂度为O(n)的情况下完成这个任务吗? 你可以假定返回的数组不算在额外空间内。

*/


vector<int> findDisappearedNumbers(vector<int>& nums) 
{
    vector<int> disappear_vector;
    for (int i = 0; i < nums.size(); i++)
    {
        int idx = abs(nums[i]) - 1;
        if (nums[idx] > 0)
        {
            nums[idx] *= -1;
        }
    }
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > 0)
        {
            disappear_vector.push_back(i + 1);
        }
    }
    return disappear_vector;
}

SCENARIO("findDisappearedNumbers") 
{
    GIVEN("findDisappearedNumbers") 
    {
        WHEN("input [4,3,2,7,8,2,3,1]") 
        {
            vector<int> nums = { 4,3,2,7,8,2,3,1 };
            vector<int> disappear_vector = { 5,6 };

            THEN("get [5,6]") 
            {
                REQUIRE(findDisappearedNumbers(nums) == disappear_vector);
            }
        }
    }
}

