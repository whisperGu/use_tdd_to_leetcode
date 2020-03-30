77. 组合
难度
中等

232





给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。
示例:
输入: n = 4, k = 2
输出:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]

class Solution {
public:
    vector<vector<int>> ans;
    
    vector<vector<int>> combine(int n, int k) {
        vector<int> v;
        dfs(1,n,v,k);
        return ans;
    }
    void dfs(int l,int n , vector<int> &v, int k)
    {
        if (v.size() == k)
        {
            ans.push_back(v);
            return;
        }
        for (int i = l; i <= n; i++)
        {
            v.push_back(i);
            dfs(i+1, n, v, k);
            v.pop_back();
        }
        return;

    }
};