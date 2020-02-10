编写一个遍历游程编码序列的迭代器。

迭代器由 RLEIterator(int[] A) 初始化，其中 A 是某个序列的游程编码。更具体地，对于所有偶数 i，A[i] 告诉我们在序列中重复非负整数值 A[i + 1] 的次数。

迭代器支持一个函数：next(int n)，它耗尽接下来的  n 个元素（n >= 1）并返回以这种方式耗去的最后一个元素。如果没有剩余的元素可供耗尽，则  next 返回 -1 。

例如，我们以 A = [3,8,0,9,2,5] 开始，这是序列 [8,8,8,5,5] 的游程编码。这是因为该序列可以读作 “三个八，零个九，两个五”。

 

示例：

输入：["RLEIterator","next","next","next","next"], [[[3,8,0,9,2,5]],[2],[1],[1],[2]]
输出：[null,8,8,5,-1]
解释：
RLEIterator 由 RLEIterator([3,8,0,9,2,5]) 初始化。
这映射到序列 [8,8,8,5,5]。
然后调用 RLEIterator.next 4次。

.next(2) 耗去序列的 2 个项，返回 8。现在剩下的序列是 [8, 5, 5]。

.next(1) 耗去序列的 1 个项，返回 8。现在剩下的序列是 [5, 5]。

.next(1) 耗去序列的 1 个项，返回 5。现在剩下的序列是 [5]。

.next(2) 耗去序列的 2 个项，返回 -1。 这是由于第一个被耗去的项是 5，
但第二个项并不存在。由于最后一个要耗去的项不存在，我们返回 -1。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/rle-iterator
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

/*
算法
如果我们调用 next(n)，即删除 n 个元素，那么对于当前的元素 A[i + 1]，我们还可以删除的次数为 D = A[i] - q。
如果 n > D，那么我们会删除所有的 A[i + 1]，并迭代到下一个元素，即 n -= D; i += 2; q = 0。
如果 n <= D，那么我们删除的最后一个元素就为 A[i + 1]，即 q += D; return A[i + 1]。


直接展开内存会超
class RLEIterator {
public:
    deque<int> rle;
    RLEIterator(vector<int>& A) {
        for (int i = 0; i < A.size(); i+=2)
        {
            int digital = A[i+1];
            int digital_nums = A[i];
            for (int j = 0; j < digital_nums; j++)
            {
                rle.push_back(digital);
            }
        }
    }
    
    int next(int n) {
        int ans = -1;
        if (n > rle.size())
        {
            return -1;
        }
        while (n)
        {
            if (n == 1)
            {
                ans = rle.front();
            }
            rle.pop_front();
            n--;
        }
        return ans;
    }
};
*/

class RLEIterator {
public:
    int current_delete_digital_pos;
    int current_digital_deleted_nums;
    vector<int> v;

    RLEIterator(vector<int>& A) {
        current_delete_digital_pos = 0;
        current_digital_deleted_nums = 0;
        v = A;
    }
    
    int next(int n) {
        while(n)
        {
            if (current_delete_digital_pos == -1)
            {
                return -1;
            }

            int current_digit_nums = v[current_delete_digital_pos];
            int remain_digit_nums = current_digit_nums - current_digital_deleted_nums;

            if (n > remain_digit_nums )
            {
                n -= remain_digit_nums;
                if (current_delete_digital_pos + 2 >= v.size())
                {
                    return -1;
                }
                current_delete_digital_pos += 2;
                current_digital_deleted_nums = 0;
            }
            else if (n < remain_digit_nums )
            {
                current_digital_deleted_nums += n;
                n = 0;
                return v[current_delete_digital_pos+1];
            }
            else
            {
                int ans = v[current_delete_digital_pos+1];
                if (current_delete_digital_pos + 2 >= v.size())
                {
                    current_delete_digital_pos =  -1;
                }
                else
                {
                    current_delete_digital_pos += 2;
                    current_digital_deleted_nums = 0;
                }
                n = 0;
                return ans;

            }
        }
        return -1;
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(A);
 * int param_1 = obj->next(n);
 */