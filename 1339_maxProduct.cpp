
/*
给你一棵二叉树，它的根为 root 。请你删除 1 条边，使二叉树分裂成两棵子树，且它们子树和的乘积尽可能大。

由于答案可能会很大，请你将结果对 10^9 + 7 取模后再返回。

*/
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
    long long TreeSum(TreeNode* root)
    {
        if (root == NULL)
        {
            return 0;
        }
        long long x = TreeSum(root->left);
        long long y = TreeSum(root->right);
        return root->val+x+y;
    }

    long long subTreeMulti(TreeNode* root, long long sum1, long long &res)
    {
        if (root == NULL)
        {
            return 0;
        }
        int left_sum = subTreeMulti(root->left, sum1, res);
        int right_sum = subTreeMulti(root->right, sum1, res);
        int subSum = root->val + left_sum + right_sum;

        res = max(subSum*(sum1-subSum), res);
        return subSum;
    }

    int maxProduct(TreeNode* root) {
        long long treeSum = TreeSum(root);
        long long res = 0;
        subTreeMulti(root, treeSum, res);
        return res % (long long)(1e9+7);

        
    }
};
