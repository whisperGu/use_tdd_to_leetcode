/*
 * Author: YangGu 
 *   Date: 2020/2/5
*/

#define CATCH_CONFIG_MAIN  

#include <catch.hpp>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;
/*
设计一个简化版的推特(Twitter)，可以让用户实现发送推文，关注/取消关注其他用户，
能够看见关注人（包括自己）的最近十条推文。你的设计需要支持以下的几个功能：


    postTweet(userId, tweetId): 创建一条新的推文
    getNewsFeed(userId): 
    检索最近的十条推文。每个推文都必须是由此用户关注的人或者是用户自己发出的。
    推文必须按照时间顺序由最近的开始排序。
    follow(followerId, followeeId): 关注一个用户
    unfollow(followerId, followeeId): 取消关注一个用户


示例:

Twitter twitter = new Twitter();

// 用户1发送了一条新推文 (用户id = 1, 推文id = 5).
twitter.postTweet(1, 5);

// 用户1的获取推文应当返回一个列表，其中包含一个id为5的推文.
twitter.getNewsFeed(1);

// 用户1关注了用户2.
twitter.follow(1, 2);

// 用户2发送了一个新推文 (推文id = 6).
twitter.postTweet(2, 6);

// 用户1的获取推文应当返回一个列表，其中包含两个推文，id分别为 -> [6, 5].
// 推文id6应当在推文id5之前，因为它是在5之后发送的.
twitter.getNewsFeed(1);

// 用户1取消关注了用户2.
twitter.unfollow(1, 2);

// 用户1的获取推文应当返回一个列表，其中包含一个id为5的推文.
// 因为用户1已经不再关注用户2.
twitter.getNewsFeed(1);

*/

/* 自己实现的，有缺陷，没有考虑到tiwter时间线的问题
class Twitter {
public:
    unordered_map<int, vector<int>> user_newsfeed_map;
    unordered_map<int, vector<int>> user_follows_map;
    unordered_map<int, vector<int>> user_whofollows_me_map;


    void postTweet(int userId, int tweetId)
    {
        vector<int> update_news_feed = user_newsfeed_map[userId];
        update_news_feed.insert(update_news_feed.begin(), tweetId);
        user_newsfeed_map[userId] = update_news_feed;

        vector<int> whofollows_me = user_whofollows_me_map[userId];
        for (auto it = whofollows_me.begin(); it != whofollows_me.end(); it++)
        {
            update_news_feed = user_newsfeed_map[*it];
            update_news_feed.insert(update_news_feed.begin(), tweetId);
            user_newsfeed_map[*it] = update_news_feed;
        }
    }

    vector<int> getNewsFeed(int userId)
    {
        vector<int> newsfeed = user_newsfeed_map[userId];
        return newsfeed;
    }

    void follow(int followerId, int followeeId) 
    {
        if (alreadyIsFollows(followerId, followeeId))
        {
            return;
        }
        user_follows_map[followerId].push_back(followeeId);
        user_whofollows_me_map[followeeId].push_back(followerId);

        vector<int> follower_newsfeed = getNewsFeed(followerId);   
        vector<int> followee_newsfeed = getNewsFeed(followeeId);
        if (followee_newsfeed.empty())
        {
            return;
        }


  
    }

    void unfollow(int followerId, int followeeId) 
    {
        vector<int> follows = user_follows_map[followerId];
        for (auto it = follows.begin(); it != follows.end(); it++)
        {
            if (*it == followeeId)
            {
                follows.erase(it);
                user_follows_map[followerId] = follows;
                break;
            }
        }
        vector<int> whofollows_me = user_whofollows_me_map[followeeId];
        for (auto it = follows.begin(); it != follows.end(); it++)
        {
            if (*it == followerId)
            {
                whofollows_me.erase(it);
                user_whofollows_me_map[followeeId] = whofollows_me;
                break;
            }
        }
        vector<int> follower_newsfeed = getNewsFeed(followerId);

        vector<int> followee_newsfeed = getNewsFeed(followeeId);
        if (followee_newsfeed.empty())
        {
            return;
        }
        vector<int> update_follower_newsfeed;
        for (auto it = follower_newsfeed.begin(); it != follower_newsfeed.end(); it++)
        {
            for (auto it2 = followee_newsfeed.begin(); it2 != followee_newsfeed.end(); it2++)
            {
                if (*it2 == *it)
                {
                    break;
                }
                update_follower_newsfeed.push_back(*it);
            }
        }
        user_newsfeed_map[followerId] = update_follower_newsfeed;
    }

    bool alreadyIsFollows(int userId, int followeeId)
    {
        vector<int> follows = user_follows_map[userId];
        for (int i = 0; i < follows.size(); i++)
        {
            if (followeeId == follows[i])
            {
                return true;
            }
        }
        return false;

    }
    vector<int> getfollows(int userId)
    {
        vector<int> newsfeed = user_follows_map[userId];
        return newsfeed;
    }

};

SCENARIO("Twitter Simulation ") 
{
    GIVEN("Twitter App") 
    {
        
        WHEN("user_id = 1, send tweet_id = 5") 
        {
            Twitter *ptwitter = new Twitter();
            ptwitter->postTweet(1, 5);
            
            THEN("user_id = 1， getNewsFeed为tweet_id = 5") 
            {
                vector<int> newsfeed = { 5 };
                REQUIRE(ptwitter->getNewsFeed(1) == newsfeed);
            }
        }

        WHEN("user_id = 1, send tweet_id = 5 and send tweet_id = 6 ")
        {
            Twitter* ptwitter = new Twitter();
            ptwitter->postTweet(1, 5);
            ptwitter->postTweet(1, 6);

            THEN("user_id = 1， getNewsFeed为tweet_id = 6,5")
            {
                vector<int> newsfeed = { 6,5 };
                REQUIRE(ptwitter->getNewsFeed(1) == newsfeed);
            }
        }

        WHEN("user_id = 1,follow user_id = 2 ")
        {
            Twitter* ptwitter = new Twitter();
            ptwitter->follow(1, 2);

            THEN("user_id = 1， get follow = 2")
            {
                vector<int> his_follows = { 2 };
                REQUIRE(ptwitter->getfollows(1) == his_follows);
            }
        }

        WHEN("user_id = 1,follow user_id = 2,3 ")
        {
            Twitter* ptwitter = new Twitter();
            ptwitter->follow(1, 2);
            ptwitter->follow(1, 3);

            THEN("user_id = 1， get follow = 2,3")
            {
                vector<int> his_follows = { 2,3 };
                REQUIRE(ptwitter->getfollows(1) == his_follows);
            }
        }

        WHEN("user_id = 1, folow userid=2,3, un follow user_id = 2 ")
        {
            Twitter* ptwitter = new Twitter();
            ptwitter->follow(1, 2);
            ptwitter->follow(1, 3);
            ptwitter->unfollow(1, 2);

            THEN("user_id = 1， get follow = 3")
            {
                vector<int> his_follows = {3};
                REQUIRE(ptwitter->getfollows(1) == his_follows);
            }
        }
       

        WHEN("user_id = 1, follow user_id = 2, and 2 post wtitter 6 ")
        {
            Twitter* ptwitter = new Twitter();
            ptwitter->follow(1, 2);
            ptwitter->postTweet(2, 6);

            THEN("user_id = 1， get wtitter = 6")
            {
                vector<int> newsfeed = { 6};
                REQUIRE(ptwitter->getNewsFeed(1) == newsfeed);
            }
        }

        WHEN("user_id = 1 post wtitter 5, follow user_id = 2, and 2 post wtitter 6 ")
        {
            Twitter* ptwitter = new Twitter();
            ptwitter->follow(1, 2);
            ptwitter->postTweet(1, 5);
            ptwitter->postTweet(2, 6);

            THEN("user_id = 1， get wtitter = 6,5")
            {
                vector<int> newsfeed = { 6,5 };
                REQUIRE(ptwitter->getNewsFeed(1) == newsfeed);
            }
        }

        WHEN("user_id = 1 , follow user_id = 2, and 2 post wtitter 6, and user_id = 1 post wtitter 5 ")
        {
            Twitter* ptwitter = new Twitter();
            ptwitter->follow(1, 2);
            ptwitter->postTweet(2, 6);
            ptwitter->postTweet(1, 5);

            THEN("user_id = 1， get wtitter = 5,6")
            {
                vector<int> newsfeed = { 5,6 };
                REQUIRE(ptwitter->getNewsFeed(1) == newsfeed);
            }
        }

        WHEN("user_id = 1 , follow user_id = 2, and 2 post wtitter 6, and user_id = 1 post wtitter 5,"
              "and follow user_id = 3, and 3 post wtitter 7")
        {
            Twitter* ptwitter = new Twitter();
            ptwitter->follow(1, 2);
            ptwitter->postTweet(2, 6);
            ptwitter->postTweet(1, 5);
            ptwitter->follow(1, 3);
            ptwitter->postTweet(1, 7);

            THEN("user_id = 1， get wtitter = 7,5,6")
            {
                vector<int> newsfeed = {7,5,6 };
                REQUIRE(ptwitter->getNewsFeed(1) == newsfeed);
            }
        }

        WHEN("user_id = 1 , follow user_id = 2, and 2 post wtitter 6, and user_id = 1 post wtitter 5,"
            "and follow user_id = 3, and 3 post wtitter 7, and id 1 unfollow 2")
        {
            Twitter* ptwitter = new Twitter();
            ptwitter->follow(1, 2);
            ptwitter->postTweet(2, 6);
            ptwitter->postTweet(1, 5);
            ptwitter->follow(1, 3);
            ptwitter->postTweet(1, 7);
            ptwitter->unfollow(1, 2);

            THEN("user_id = 1， get wtitter = 7,5")
            {
                vector<int> newsfeed = { 7,5 };
                REQUIRE(ptwitter->getNewsFeed(1) == newsfeed);
            }
        }

        WHEN("user_id = 1 post wtitter 1,  2  follow 1 ")
        {
            Twitter* ptwitter = new Twitter();
           
            ptwitter->postTweet(1, 1);
            ptwitter->follow(2, 1);


            THEN("user_id = 2， get wtitter = 1")
            {
                vector<int> newsfeed = { 1 };
                REQUIRE(ptwitter->getNewsFeed(2) == newsfeed);
            }
        }
    }
}
*/
/* java 实现的正确答案
public class Twitter {
    private Map<Integer, Set<Integer>> followeeMap;

    private Map<Integer, Integer> tweetToUserMap;

    private List<Integer> list;

    public Twitter() {
        followeeMap = new HashMap<>();
        tweetToUserMap = new HashMap<>();
        list = new ArrayList<>();
    }

    public void postTweet(int userId, int tweetId) {
        tweetToUserMap.put(tweetId, userId);
        list.add(tweetId);
    }

    public List<Integer> getNewsFeed(int userId) {
        List<Integer> result = new ArrayList<>();
        for (int i = list.size() - 1; i >= 0 && result.size() < 10; i--) {
            int owner = tweetToUserMap.get(list.get(i));
            if (owner == userId || (followeeMap.containsKey(userId) && followeeMap.get(userId).contains(owner))) {
                result.add(list.get(i));
            }
        }
        return result;
    }

    public void follow(int followerId, int followeeId) {
        if (!followeeMap.containsKey(followerId)) {
            followeeMap.put(followerId, new HashSet<>());
        }
        followeeMap.get(followerId).add(followeeId);
    }

    public void unfollow(int followerId, int followeeId) {
        if (followeeMap.containsKey(followerId)) {
            followeeMap.get(followerId).remove(followeeId);
        }
    }
}
*/


