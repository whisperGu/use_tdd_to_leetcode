有个内含单词的超大文本文件，给定任意两个单词，找出在这个文件中这两个单词的最短距离(相隔单词数)。如果寻找过程在这个文件中会重复多次，而每次寻找的单词不同，你能对此优化吗?

示例：

输入：words = ["I","am","a","student","from","a","university","in","a","city"], word1 = "a", word2 = "student"
输出：1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-closest-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


class Solution {
public:
    int findClosest(vector<string>& words, string word1, string word2) {

        int a = -1;
        int b = -1;

        int Ans = words.size() + 1;

        for (int i = 0; i < words.size(); i++)
        {
            if (words[i]==word1)
            {
                a=i;
                if (b!=-1) Ans=min(Ans,a-b);
            }
            else if (words[i]==word2)
            {
                b=i;
                if (a!=-1) Ans=min(Ans,b-a);
            }
        }

        return Ans;
        
    }
};

