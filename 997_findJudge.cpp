/*
 * Author: YangGu 
 *   Date: 2020/2/3
*/

#define CATCH_CONFIG_MAIN  

#include <catch.hpp>
#include <vector>


using namespace std;
/*
在一个小镇里，按从 1 到 N 标记了 N 个人。传言称，这些人中有一个是小镇上的秘密法官。
如果小镇的法官真的存在，那么：

    小镇的法官不相信任何人。
    每个人（除了小镇法官外）都信任小镇的法官。
    只有一个人同时满足属性 1 和属性 2 。

给定数组 trust，该数组由信任对 trust[i] = [a, b] 组成，表示标记为 a 的人信任标记为 b 的人。
如果小镇存在秘密法官并且可以确定他的身份，请返回该法官的标记。否则，返回 -1。
*/

int findJudge(int N, vector<vector<int>>& trust)
{
    vector<int> trust_cnt(N+1, 0);

    for (int i = 0; i < trust.size(); i++)
    {
        trust_cnt[trust[i][1]] ++;
    }
    int judge = -1;
    for (int i = 1; i < trust_cnt.size(); i++)
    {
        if (trust_cnt[i] == N - 1)
        {
            judge = i;
            continue;
        }
    }
    for (int i = 0; i < trust.size(); i++)
    {
        if (judge == trust[i][0])
        {
            judge = -1;
            continue;
        }
    }
    return judge;
}

SCENARIO("findJudge in trust vector") 
{
    GIVEN("findJudge") 
    {
        WHEN("input trust = [[1,2]], N = 2") 
        {
            int N = 2;
            vector<vector<int>> trust_vector = { {1,2} };

            THEN("judge is 2") 
            {
                REQUIRE(findJudge(N, trust_vector) == 2);
            }
        }

        WHEN("input N = 3, trust = [[1,3],[2,3]]")
        {
            int N = 3;
            vector<vector<int>> trust_vector = { {1,3},{2,3} };

            THEN("judge is 3")
            {
                REQUIRE(findJudge(N, trust_vector) == 3);
            }
        }

        WHEN("input N = 4, trust = [[1,3],[1,4],[2,3],[2,4],[4,3]]")
        {
            int N = 4;
            vector<vector<int>> trust_vector = { {1,3},{1,4},{2,3},{2,4},{4,3} };

            THEN("judge is 3")
            {
                REQUIRE(findJudge(N, trust_vector) == 3);
            }
        }
    }
}

