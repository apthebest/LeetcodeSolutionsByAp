#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2)
    {

        // ptr1 will get us the previous pointer to node at a
        ListNode *ptr1 = list1;
        // ptr2 will get us the node at b
        ListNode *ptr2 = list1;

        // creating a dummy head
        ListNode *newHead = new ListNode(100);
        newHead->next = list1;

        while (b--)
            ptr2 = ptr2->next;
        while (--a)
            ptr1 = ptr1->next;

        // setting the next pointer of prev to 'a' as list2'head node
        ptr1->next = list2;

        // to get the last pointer if list2
        ListNode *ptr = list2;

        while (ptr && ptr->next)
            ptr = ptr->next;

        // setting the next pointer of last node of list2 = next pointer to node
        // at b
        ptr->next = ptr2->next;

        // returning the dummyHead next node
        return newHead->next;
    }
};