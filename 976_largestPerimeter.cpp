976. 三角形的最大周长
难度
简单

54





给定由一些正数（代表长度）组成的数组 A，返回由其中三个长度组成的、面积不为零的三角形的最大周长。
如果不能形成任何面积不为零的三角形，返回 0。
 

示例 1：
输入：[2,1,2]
输出：5


 /**
     * 方案二：选择排序，提前筛选 [LeetCode:14ms]
     */
    class Solution2 {
        public int largestPerimeter(int[] A) {
            for (int i = 0; i < A.length; i++) {
                int minP = i;
                for (int j = i + 1; j < A.length; j++) {
                    if (A[j] > A[minP]) {
                        minP = j;
                    }
                }
                int temp = A[i];
                A[i] = A[minP];
                A[minP] = temp;
                if (i >= 2 && A[i - 2] < A[i - 1] + A[i])
                    return A[i] + A[i - 1] + A[i - 2];
            }
            return 0;
        }
    }
