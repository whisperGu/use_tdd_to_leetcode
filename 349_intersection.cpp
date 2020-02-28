
349. 两个数组的交集
给定两个数组，编写一个函数来计算它们的交集。

示例 1:

输入: nums1 = [1,2,2,1], nums2 = [2,2]
输出: [2]
示例 2:

输入: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
输出: [9,4]
说明:

输出结果中的每个元素一定是唯一的。
我们可以不考虑输出结果的顺序。


public int[] intersection(int[] nums1, int[] nums2) {
LinkedList<Integer> list = new LinkedList<>();
    int p = 0;
    HashSet<Integer> set = new HashSet<>();
    for (int n1 : nums1) {
        set.add(n1);
    }

    for (int n2 : nums2) {
        if (set.contains(n2)) { // 可找到相同元素
            list.addLast(n2);   // 添加到list中
            set.remove(n2);     // 保证交集元素互异
        }
    }
    if (list.size() == 0) {     // 如果交集是空集，则返回空数组[]
        return new int[] {};
    }
    int[] resArr = new int[list.size()];
    for(int n : list) { 
        resArr[p++] = n;
    }
    return resArr;
}
