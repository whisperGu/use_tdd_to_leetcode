给出第一个词 first 和第二个词 second，考虑在某些文本 text 中可能以 "first second third" 形式出现的情况，其中 second 紧随 first 出现，third 紧随 second 出现。

对于每种这样的情况，将第三个词 "third" 添加到答案中，并返回答案。

 

示例 1：

输入：text = "alice is a good girl she is a good student", first = "a", second = "good"
输出：["girl","student"]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/occurrences-after-bigram
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> split_by_space;
        string c = " ";
        string::size_type right = text.find(c);  
        string::size_type left = 0;
        while (right != string::npos) 
        {
            split_by_space.push_back(text.substr(left, right-left));
            left = right + c.size();
            right = text.find(" ", left);  
        }
        split_by_space.push_back(text.substr(left, text.size()-left));

        vector<string> ans;
        for (int i = 0; i < split_by_space.size();i++)
        {
            if (split_by_space[i] == first)
            {
                if (i+1 < split_by_space.size() && split_by_space[i+1] == second)
                {

                    if (i+2 < split_by_space.size())
                    {
                        
                        ans.push_back(split_by_space[i+2]);
                    }
                }
            }
        }
        return ans;
    }
};