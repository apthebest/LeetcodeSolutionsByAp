#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode()
    {
        this->val = 0;
        this->next = NULL;
    }
    ListNode(int val)
    {
        this->val = val;
        this->next = NULL;
    }

    // ListNode() : val(0), next(nullptr){} * ListNode(int x) : val(x), next(nullptr){} * ListNode(int x, ListNode *next) : val(x), next(next){}
};
class Solution
{
public:
    void reorderList(ListNode *head)
    {
        // to calculate the length of the list
        int length = 0;
        ListNode *ptr = head;
        while (ptr)
        {
            ptr = ptr->next;
            length++;
        }
        ptr = head;

        int half_length = length / 2 + length % 2;

        // partition the list in two halves
        while (ptr && --half_length)
        {
            ptr = ptr->next;
        }

        // if the length of list is greater than 1
        if (ptr)
        {
            ListNode *next = ptr->next;
            ptr->next = NULL;

            // stack will store the nodes in the second half of the list
            stack<ListNode *> stack;
            while (next)
            {
                stack.push(next);
                next = next->next;
            }
            ptr = head;

            while (ptr && !stack.empty())
            {
                next = ptr->next;

                // set the next pointer of curr_list as the top of stack's node value
                // essentially this is the part where the shuffle happens
                ptr->next = new ListNode(stack.top()->val);
                stack.pop();
                ptr = ptr->next;
                ptr->next = next;
                ptr = ptr->next;
            }
        }
    }
};
