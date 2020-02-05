/*
 * Author: YangGu 
 *   Date: 2020/2/5
*/

#define CATCH_CONFIG_MAIN  

#include <catch.hpp>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;


 /**
 给定一个二叉树，判断它是否是高度平衡的二叉树。

本题中，一棵高度平衡二叉树定义为：


一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。


示例 1:

给定二叉树 [3,9,20,null,null,15,7]

    3
   / \
  9  20
    /  \
   15   7

返回 true 。

  * Definition for a binary tree node.
  * struct TreeNode {
  *     int val;
  *     TreeNode *left;
  *     TreeNode *right;
  *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  * };
  */

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int TreeHeight(TreeNode* root)
{
    if (root == nullptr)
    {
        return 0;
    }
    if (root->left == nullptr && root->right == nullptr)
    {
        return 1;
    }
    int left_height = TreeHeight(root->left);
    if (left_height == -1)
    {
        return -1;
    }
    int right_height = TreeHeight(root->right);
    if (right_height == -1)
    {
        return -1;
    }
    if (abs(left_height - right_height) > 1)
    {
        return -1;
    }
    return max(left_height, right_height) + 1;

}


bool isBalanced(TreeNode* root) 
{
    return TreeHeight(root) != -1;
}

int string_to_int(string str)
{
    return (int)atoi(str.c_str());
}

TreeNode* make_tree_by_arr(string* arr, int n)
{
    if (n == 1 && arr[0] == "null")
    {
        return nullptr;
    }

    TreeNode* root = new TreeNode(string_to_int(arr[0]));
    queue<TreeNode*> q;
    q.push(root);
    int i = 0;
    while (!q.empty() && i < (n/2))
    {
        TreeNode* p = q.front();
        q.pop();
        if (arr[2 * i + 1] != "null")
        {
            p->left = new TreeNode(string_to_int(arr[2 * i + 1]));
            q.push(p->left);
        }
        if (arr[2 * i + 2] != "null")
        {
            p->right = new TreeNode(string_to_int(arr[2 * i + 2]));
            q.push(p->right);
        }
        i++;
    }
    return root;

}

void show_tree_pre(TreeNode* root)
{
    if (root == nullptr)
    {
        cout << "null" << " ";
        return;
    }
    cout << root->val << " ";
    show_tree_pre(root->left);
    show_tree_pre(root->right);
}

void show_tree_mid(TreeNode* root)
{
    if (root == nullptr)
    {
        cout << "null" << " ";
        return;
    }
    show_tree_mid(root->left);
    cout << root->val << " ";
    show_tree_mid(root->right);
}


SCENARIO("isBalanced ") 
{
    GIVEN("isBalanced") 
    {
        
        WHEN("tree is [3,9,20,null,null,15,7]") 
        {
            string array[] = { "3","9","20","null","null","15","7" };
            TreeNode* root = make_tree_by_arr(array, sizeof(array)/sizeof(string));
            show_tree_pre(root);
            cout << endl;
            show_tree_mid(root);
            cout << endl;
            THEN("tree is Balanced ") 
            {
                REQUIRE(isBalanced(root) == true);
            }
        }

    }
}



