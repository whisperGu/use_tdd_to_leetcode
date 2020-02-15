给你一个按 YYYY-MM-DD 格式表示日期的字符串 date，请你计算并返回该日期是当年的第几天。

通常情况下，我们认为 1 月 1 日是每年的第 1 天，1 月 2 日是每年的第 2 天，依此类推。每个月的天数与现行公元纪年法（格里高利历）一致。

 

示例 1：

输入：date = "2019-01-09"
输出：9

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/day-of-the-year
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution {
public:
    void SplitString(const std::string& s, std::vector<std::string>& v, const std::string& c)
    {
        std::string::size_type pos1, pos2;
        pos2 = s.find(c);
        pos1 = 0;
        while(std::string::npos != pos2)
        {
            v.push_back(s.substr(pos1, pos2-pos1));
        
            pos1 = pos2 + c.size();
            pos2 = s.find(c, pos1);
        }
        if(pos1 != s.length())
            v.push_back(s.substr(pos1));
    }

    bool isLeapYear(int year)
    {
        if ( (year % 400 == 0) || (year%4==0 && year % 100 != 0))
        {
            return true;
        }
        return false;
    }

    int dayOfYear(string date) {
        vector<string> v;
        SplitString( date, v, "-");
        vector<int> Monthday = {31,28,31,30,31,30,31,31,30,31,30,31};
        int year = atoi(v[0].c_str());
        int month = atoi(v[1].c_str());
        int day = atoi(v[2].c_str());
        if (isLeapYear(year))
        {
            Monthday[1] = 29;
        }

        int ans = day;
        for (int i = 0; i <month-1;i++)
        {
            ans += Monthday[i];
        }
        return ans;

    }
};
