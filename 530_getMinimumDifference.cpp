530. 二叉搜索树的最小绝对差
难度
简单

90





给定一个所有节点为非负值的二叉搜索树，求树中任意两节点的差的绝对值的最小值。
示例 :
输入:

   1
    \
     3
    /
   2

输出:
1

class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
		vector<int> v;
		midOrderLook(root, v);
		int mini_differ = (int)(1<<31 - 1);
		for (int i = 0 ; i < v.size(); i++)
		{
			if (i + 1 < v.size())
			{
				mini_differ = min(mini_differ, abs(v[i] - v[i+1]));
			}
		}
		
		return mini_differ;
    }
	
	void midOrderLook(TreeNode* root, vector<int> &v)
	{
		if (root == NULL)
		{
			return;
		}
		midOrderLook(root->left, v);
		v.push_back(root->val);
		midOrderLook(root->right, v);
	}
	
};