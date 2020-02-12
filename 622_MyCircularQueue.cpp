/*
设计你的循环队列实现。 循环队列是一种线性数据结构，其操作表现基于 FIFO（先进先出）原则并且队尾被连接在队首之后以形成一个循环。它也被称为“环形缓冲器”。

循环队列的一个好处是我们可以利用这个队列之前用过的空间。在一个普通队列里，一旦一个队列满了，我们就不能插入下一个元素，即使在队列前面仍有空间。但是使用循环队列，我们能使用这些空间去存储新的值。

你的实现应该支持如下操作：


	MyCircularQueue(k): 构造器，设置队列长度为 k 。
	Front: 从队首获取元素。如果队列为空，返回 -1 。
	Rear: 获取队尾元素。如果队列为空，返回 -1 。
	enQueue(value): 向循环队列插入一个元素。如果成功插入则返回真。
	deQueue(): 从循环队列中删除一个元素。如果成功删除则返回真。
	isEmpty(): 检查循环队列是否为空。
	isFull(): 检查循环队列是否已满。

*/
class MyCircularQueue {
    int* data;
    int size;
    int head;
    int tail;    
    int capicity;
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        data = new int[k];
        size = k;
        head = 0;
        tail = 0;  
        capicity = 0;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (capicity < size) {
            data[tail++] = value;
            ++capicity;
            if (tail == size) {
                tail = 0;
            }
            return true;
        }
        return false;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (capicity > 0) {
            ++head;
            --capicity;
            if (head == size) {
                head = 0;
            }
            return true;
        }
        return false;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if (capicity == 0) {
            return -1;
        }
        return data[head];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if (capicity == 0) {
            return -1;
        }
        return tail == 0 ? data[size - 1] : data[tail - 1];   
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return capicity == 0;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return capicity == size;
    }
};

