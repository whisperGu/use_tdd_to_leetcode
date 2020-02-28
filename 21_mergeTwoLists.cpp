21. 合并两个有序链表
将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

示例：

输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void showLink(ListNode* l1)
    {
        ListNode*  p = l1;
        while(p)
        {
            cout<<p->val<<"->";
            p = p->next;
        }
        cout<<endl;
    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = NULL;
        if (l1 == NULL || l2 == NULL)
        {
            return l1 == NULL ? l2 : l1;
        }
        if (l1->val <= l2->val)
        {
            head = l1;
            if (l1->next == NULL)
            {
                head->next = l2;
                return head;
            }
            else
            {
                l1 = l1->next;
            }
        }
        else
        {
            head = l2;
            if (l2->next == NULL)
            {
                head->next = l1;
                return head;
            }
            else
            {
                l2 = l2->next;
            }
        }
        ListNode* p = head;
        while(l1 != NULL && l2 != NULL)
        {
            if (l1->val <= l2->val)
            {
                p->next = l1;
                l1 = l1->next;
            }
            else
            {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        //showLink(head);
        if (l1 != NULL)
        {
            p->next = l1;
        }
        //showLink(head);
        if (l2 != NULL)
        {
            p->next = l2;
        }
        //showLink(head);
        return head;
    }
};

/*
简洁方法：
class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        
        ListNode prehead = new ListNode(-1);

        ListNode prev = prehead;
        while (l1 != null && l2 != null) {
            if (l1.val <= l2.val) {
                prev.next = l1;
                l1 = l1.next;
            } else {
                prev.next = l2;
                l2 = l2.next;
            }
            prev = prev.next;
        }

        prev.next = l1 == null ? l2 : l1;

        return prehead.next;
    }
}

*/