#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Definition for singly-linked list.
struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
  bool hasCycle(ListNode *head)
  {
    if (!head)
      return false;

    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
      slow = slow->next;
      fast = fast->next->next;
      if (slow == fast)
      {
        return true;
      }
    }
    return false;
  }
};

int main()
{
  ListNode *l1 = new ListNode(3);
  ListNode *l2 = new ListNode(2);
  ListNode *l3 = new ListNode(0);
  ListNode *l4 = new ListNode(4);
  l1->next = l2;
  l2->next = l3;
  l3->next = l4;
  l4->next = l2;

  Solution solution;
  cout << solution.hasCycle(l1);

  return 0;
}
