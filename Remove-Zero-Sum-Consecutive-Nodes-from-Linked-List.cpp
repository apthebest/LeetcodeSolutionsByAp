#include <bits/stdc++.h>
#include <tr1/unordered_map>
using namespace std;

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
    ListNode *removeZeroSumSublists(ListNode *head)
    {
        ListNode *newHead = new ListNode();
        newHead->next = head;
        unordered_map<int, ListNode *> map;
        map[0] = newHead;
        ListNode *ptr = head;
        int prefix_sum = 0;

        while (ptr)
        {
            prefix_sum += ptr->val;
            if (map.count(prefix_sum))
            {
                ListNode *prevNode = map[prefix_sum];
                ListNode *node_to_be_removed = prevNode->next;
                int start_sum = prefix_sum + node_to_be_removed->val;
                while (node_to_be_removed != ptr)
                {
                    map.erase(start_sum);
                    node_to_be_removed = node_to_be_removed->next;
                    start_sum += node_to_be_removed->val;
                }
                prevNode->next = ptr->next;
            }
            else
                map[prefix_sum] = ptr;
            ptr = ptr->next;
        }
        return newHead->next;
    }
};
