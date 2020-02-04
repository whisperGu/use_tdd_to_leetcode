/*
 * Author: YangGu 
 *   Date: 2020/2/4
*/

#define CATCH_CONFIG_MAIN  

#include <catch.hpp>
#include <vector>


using namespace std;
/*
给定长度分别为 m 和 n 的两个数组，其元素由 0-9 构成，表示两个自然数各位上的数字。
现在从这两个数组中选出 k (k <= m + n) 个数字拼接成一个新的数，要求从同一个数组中取出的数字保持其在原数组中的相对顺序。

求满足该条件的最大数。结果返回一个表示该最大数的长度为 k 的数组。

输入:
nums1 = [6, 7]
nums2 = [6, 0, 4]
k = 5
输出:
[6, 7, 6, 0, 4]
*/

vector<int> maxSequece(vector<int>& v, int k)
{
    vector<int> ans;
    if (k >= v.size())
    {
        return v;
    }
    int max_pop_num = v.size() - k;
    for (int i = 0; i < v.size(); i++)
    {
        while (!ans.empty() && v[i] > ans.back() && max_pop_num-- > 0)
        {
            ans.pop_back();
        }
        ans.push_back(v[i]);
    }
    return ans;
}

vector<int> merge_two_sequece(vector<int> v1, vector<int> v2)
{
    vector<int> res;    
    while (v1.size() + v2.size()) {
        vector<int>& tmp = v1 > v2 ? v1 : v2;
        res.push_back(tmp[0]);
        tmp.erase(tmp.begin());
    }
    return res;
}

vector<int> get_bigger_sequece(vector<int>& v1, vector<int>& v2)
{
    for (int i = 0; i < v1.size(); i++)
    {
        if (v1[i] > v2[i])
        {
            return v1;
        }
        if (v1[i] < v2[i])
        {
            return v2;
        }
    }
    return v1;

}

vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) 
{
    int s1_size = nums1.size();
    int s2_size = nums2.size();

    vector<int> ans;
    for (int nums_from_s1 = max(0, k - s2_size); nums_from_s1 <= min(k, s1_size); nums_from_s1++)
    {
        vector<int> max_sequece_from_nums1 = maxSequece(nums1, nums_from_s1);
        vector<int> max_sequece_from_nums2 = maxSequece(nums2, k - nums_from_s1);
        vector<int> merge_max_sequece = merge_two_sequece(max_sequece_from_nums1, max_sequece_from_nums2);
        if (ans.empty())
        {
            ans = merge_max_sequece;
        }
        else
        {
            ans = get_bigger_sequece(ans, merge_max_sequece);
        }
    }
    return ans;
}


SCENARIO("maxNumber") 
{
    GIVEN("maxNumber") 
    {
        WHEN("input nums1=[3, 4, 6, 5], nums2=[9, 1, 2, 5, 8, 3], k=5") 
        {
            vector<int> nums1 = { 3,4,6,5 };
            vector<int> nums2 = { 9,1,2,5,8,3 };
            int k = 5;
            
            THEN("get [9, 8, 6, 5, 3]") 
            {
                vector<int> ans = { 9,8,6,5,3 };
                REQUIRE(maxNumber(nums1, nums2, k) == ans);
            }
        }

        WHEN("input nums1=[6，7], nums2=[6，0，4], k=5")
        {
            vector<int> nums1 = { 6,7 };
            vector<int> nums2 = { 6,0,4 };
            int k = 5;

            THEN("get [6, 7, 6, 0, 4]")
            {
                vector<int> ans = { 6,7,6,0,4 };
                REQUIRE(maxNumber(nums1, nums2, k) == ans);
            }
        }

        WHEN("input nums1=[9,1,2,5,8,3], nums2=[3,4,6,5], k=5")
        {
            vector<int> nums1 = { 9,1,2,5,8,3 };
            vector<int> nums2 = { 3,4,6,5 };
            int k = 5;

            THEN("get [9,8,6,5,3]")
            {
                vector<int> ans = { 9,8,6,5,3 };
                REQUIRE(maxNumber(nums1, nums2, k) == ans);
            }
        }

        WHEN("input nums1=[2,5,6,4,4,0], nums2=[7,3,8,0,6,5,7,6,2], k=15")
        {
            vector<int> nums1 = { 2,5,6,4,4,0 };
            vector<int> nums2 = { 7,3,8,0,6,5,7,6,2 };
            int k = 15;

            THEN("get [7,3,8,2,5,6,4,4,0,6,5,7,6,2,0]")
            {
                vector<int> ans = { 7,3,8,2,5,6,4,4,0,6,5,7,6,2,0 };
                REQUIRE(maxNumber(nums1, nums2, k) == ans);
            }
        }

    }

}

