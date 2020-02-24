953. 验证外星语词典
难度
简单

25





某种外星语也使用英文小写字母，但可能顺序 order 不同。字母表的顺序（order）是一些小写字母的排列。
给定一组用外星语书写的单词 words，以及其字母表的顺序 order，只有当给定的单词在这种外星语中按字典序排列时，返回 true；否则，返回 false。
 
示例 1：
输入：words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
输出：true
解释：在该语言的字母表中，'h' 位于 'l' 之前，所以单词序列是按字典序排列的。

public:
    bool cmp(string a,string b,string order) {
        int map[26] = {0};
        for (int i = 0; i < order.size();i++)
        {
            map[order[i]-'a'] = i;
        }
        int len = min(a.size(), b.size());
        int i = 0;
        for (int i = 0; i<len;i++)
        {
            if (a[i] != b[i])
            {
                break;
            }
            i++;
        }
        {
            return a.size() <= b.size();
        }
        else
        {
            return map[a[i] - 'a'] < map[b[i] - 'a'];
        }
        

    }

    bool isAlienSorted(vector<string>& words, string order) {
        for (int i = 0; i < words.size()-1; i++)
        {
            if (cmp(words[i], words[i+1], order) == false)
            {
                return false;
            }
        }
        return true;
    }
};


