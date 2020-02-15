给定一个二叉树，检查它是否是镜像对称的。

例如，二叉树 [1,2,2,3,4,4,3] 是对称的。

    1
   / \
  2   2
 / \ / \
3  4 4  3

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/symmetric-tree
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
    bool 
	(TreeNode* root) {
        return isSubTreeSymmetric(root, root);
    }
    bool isSubTreeSymmetric(TreeNode* root1, TreeNode* root2)
    {
        if (root1 == NULL && root2 != NULL)
        {
            return false;
        }
        if (root1 != NULL && root2 == NULL)
        {
            return false;
        }
        if (root1 == NULL && root2 == NULL)
        {
            return true;
        }

        if (root1->val != root2->val)
        {
            return false;
        }
        else
        {
            return (isSubTreeSymmetric(root1->left,root2->right) && isSubTreeSymmetric(root2->left,root1->right));
        }
            
    }
};