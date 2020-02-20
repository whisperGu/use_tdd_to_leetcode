
面试题 08.05. 递归乘法难度中等1递归乘法。 写一个递归函数，不使用 * 运算符， 实现两个正整数的相乘。可以使用加号、减号、位移，但要吝啬一些。

 示例1:

 输入：A = 1, B = 10
 输出：10

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/recursive-mulitply-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution {
public:
    int multiply(int A, int B) {
        if(A<B)swap(A,B);
        return helper(A,B);
    }
    int helper(int a,int b){
        if(b==1)return a;
        else return a+helper(b-1,a);
    }
};

