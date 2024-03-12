#include <bits/stdc++.h>
using namespace std;
#define ll long long

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
  ListNode *removeZeroSumSublists(ListNode *head)
  {
    ListNode *front = new ListNode(0, head);
    ListNode *start = front;

    while (start != NULL)
    {
      int prefixSum = 0;

      ListNode *end = start->next;

      while (end != NULL)
      {
        prefixSum += end->val;

        if (prefixSum == 0)
        {
          start->next = end->next;
        }
        end = end->next;
      }
      start = start->next;
    }

    return front->next;
  }
};

int main()
{
  ListNode *head = new ListNode(1);
  ListNode *l2 = new ListNode(2);
  ListNode *l3 = new ListNode(3);
  ListNode *l4 = new ListNode(4);
  ListNode *l5 = new ListNode(5);

  Solution s;
  s.removeZeroSumSublists(head);
  return 0;
}
