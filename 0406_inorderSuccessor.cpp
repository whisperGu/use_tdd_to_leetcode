设计一个算法，找出二叉搜索树中指定节点的“下一个”节点（也即中序后继）。

如果指定节点没有对应的“下一个”节点，则返回null。

示例 1:

输入: root = [2,1,3], p = 1

  2
 / \
1   3

输出: 2

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/successor-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。




/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        vector<TreeNode*> v;
        midOrder(root, v);
        TreeNode* ans = NULL;
        for (int i = 0; i < v.size(); i++)
        {
            if (p == v[i] && i + 1<v.size())
            {
                ans = v[i+1];
                break;
            }
        }
        return ans;
    }

    void midOrder(TreeNode* root, vector<TreeNode*> &v)
    {
        if (root == NULL)
        {
            return;
        }
        midOrder(root->left, v);
        v.push_back(root);
        midOrder(root->right, v);
    }


};