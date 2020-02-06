/*
 * Author: YangGu 
 *   Date: 2020/2/6
*/

#define CATCH_CONFIG_MAIN  

#include <catch.hpp>
#include <vector>

using namespace std;

 /**
 669
给定一个二叉搜索树，同时给定最小边界L 和最大边界 R。通过修剪二叉搜索树，
使得所有节点的值在[L, R]中 (R>=L) 。你可能需要改变树的根节点，
所以结果应当返回修剪好的二叉搜索树的新的根节点。

示例 1:

输入:
    1
   / \
  0   2

  L = 1
  R = 2

输出:
    1
      \
       2


示例 2:

输入:
    3
   / \
  0   4
   \
    2
   /
  1

  L = 1
  R = 3

输出:
      3
     /
   2
  /
 1
  */

struct TreeNode 
{
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int L, int R) 
    {
        /*
        1.当前节点不在区间，比最小值小，剪掉左边，用右子树替代，再遍历新节点，更新root
        2.当前节点不在区间，比最大致大，剪掉右边，用左子树替代，再遍历新节点，更新root
        3.节点在区间，递归遍历左边和右边 ，return root
        */
        if (root == NULL)
        {
            return NULL;
        }
        if (root->val < L)
        {
            root->left = NULL;
            root = trimBST(root->right, L, R);
            return root;
        }
        else if (root->val > R)
        {
            root->right = NULL;
            root = trimBST(root->left, L, R);
            return root;
        }
        else
        {
            root->left = trimBST(root->left, L, R);
            root->right = trimBST(root->right, L, R);
            return root;

        }

        return root;
    }
};

